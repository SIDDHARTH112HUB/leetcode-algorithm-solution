[473.matchsticks-to-square](https://leetcode.com/problems/matchsticks-to-square/)  

Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used **exactly** one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

**Example 1:**  

  
**Input:** \[1,1,2,2,2\]
  
**Output:** true
  

  
**Explanation:** You can form a square with length 2, one side of the square came two sticks with length 1.
  

**Example 2:**  

  
**Input:** \[3,3,3,3,4\]
  
**Output:** false
  

  
**Explanation:** You cannot find a way to form a square with all the matchsticks.
  

**Note:**  

1.  The length sum of the given matchsticks is in the range of `0` to `10^9`.
2.  The length of the given matchstick array will not exceed `15`.  



**Solution:**  

```cpp
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int size = nums.size();
        if( size == 0 ) return false;
        //cout<<sum<<endl;
        if( sum % 4 != 0 ) return false;
        int side_len = sum/4;
        sort(nums.begin(), nums.end(), greater<int>());
        cout<<endl;
        int cnt = 0;
        for( int i =0; i<size; i++){
            if( nums[i]>side_len )
                return false;
            vector<int> res;
            if( nums[i] > 0 ){
                bool res= solve(side_len, i, nums);
                if( res == false){
                    return false;
                }else{
                    cnt++;
                }
            }
        }
        return cnt == 4;
    }
    bool solve(int len, int i, vector<int>& nums){
        if( len == 0) return true;
        int size = nums.size();
        if( i >= size ) return false;
        if( len < 0 ) return false;
        
        bool res = solve(len-nums[i], i+1, nums);
        if( res == true)
            nums[i] = 0;
        if( res == false)
            res = solve(len, i+1, nums);
        
        return res;
    }
};
```
      