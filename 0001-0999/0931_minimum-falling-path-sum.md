[931.minimum-falling-path-sum](https://leetcode.com/problems/minimum-falling-path-sum/)  

Given a **square** array of integers `A`, we want the **minimum** sum of a _falling path_ through `A`.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

**Example 1:**

  
**Input:** \[\[1,2,3\],\[4,5,6\],\[7,8,9\]\]  
**Output:** 12  
**Explanation: **  
The possible falling paths are:  

*   `[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]`
*   `[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]`
*   `[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]`

The falling path with the smallest sum is `[1,4,7]`, so the answer is `12`.

**Constraints:**

*   `1 <= A.length == A[0].length <= 100`
*   `-100 <= A[i][j] <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<map<int, int> > vm(101);
        int ans = INT_MAX;
        for( int i = 0; i<A[0].size(); i++){
            vm[0][i] += A[0][i];
            ans = min(vm[0][i], ans);
        }
        
        for( int i = 1; i<A.size(); i++ ){
            auto &vec = A[i];
            ans = INT_MAX;
            for( int j = 0; j < vec.size(); j++){
                int n = vec[j];
                vm[i][j] = n + vm[i-1][j];
                if( j - 1 >= 0 )
                    vm[i][j] = min( vm[i-1][j-1]+n, vm[i][j]);
                if( j + 1 < vec.size() )
                    vm[i][j] = min( vm[i-1][j+1]+n, vm[i][j]);
                ans = min(ans, vm[i][j]);
            }
        }
        return ans;
    }
};
```
      