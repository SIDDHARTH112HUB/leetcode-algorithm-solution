[945.minimum-increment-to-make-array-unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique/)  

Given an array of integers A, a _move_ consists of choosing any `A[i]`, and incrementing it by `1`.

Return the least number of moves to make every value in `A` unique.

**Example 1:**

  
**Input:** \[1,2,2\]
  
**Output:** 1
  
**Explanation: ** After 1 move, the array could be \[1, 2, 3\].
  

**Example 2:**

  
**Input:** \[3,2,1,2,1,7\]
  
**Output:** 6
  
**Explanation: ** After 6 moves, the array could be \[3, 4, 1, 2, 5, 7\].
  
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
  

**Note:**

1.  `0 <= A.length <= 40000`
2.  `0 <= A[i] < 40000`  



**Solution:**  

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int M = 100002;
        int arr[100002] = {0};
        int l = -1, r=-1;
        for( int i = 0; i<A.size(); i++ ){
            arr[A[i]]++;
            
        }
        for( int i = 0; i<M; i++ ){
            if( l == -1 && arr[i] > 1 )
                l = i;
            if( l >= 0 && i > l && arr[i] == 0){
                r = i;
                break;
            }
        }
        int ans = 0;
        if( l == -1 )
            return 0;
        while( l <= M/2 ){
            if( arr[l] > 1 ){
                while( l > r || arr[r] != 0)
                    r++;
                arr[l]--;
                arr[r] = 1;
                ans += r-l;
                //cout<<l<<" "<<r <<endl;
                while(arr[r] > 0 )
                    r++;
                
            }else
                l++;
        }
        return ans;
    }
};
```
      