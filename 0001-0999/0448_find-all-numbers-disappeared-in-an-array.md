[448.find-all-numbers-disappeared-in-an-array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)  

Given an array of integers where 1 ≤ a\[i\] ≤ _n_ (_n_ = size of array), some elements appear twice and others appear once.

Find all the elements of \[1, _n_\] inclusive that do not appear in this array.

Could you do it without extra space and in O(_n_) runtime? You may assume the returned list does not count as extra space.

**Example:**

**Input:**
\[4,3,2,7,8,2,3,1\]

**Output:**
\[5,6\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int N = nums.size();
        if( N == 0 ) return ans;
        nums.push_back(nums[0]);
        N++;
        for( int i = 0; i< N; i++ ){
            int val = nums[i];
            while( val < N && val != nums[val]){
                int tmp = nums[val];
                nums[val] = val;
                val = tmp;
            }
        }
        for( int i = 1; i<N; i++ ){
            if( i != nums[i])
                ans.push_back(i);
        }
        return ans;
    }
};
```
      