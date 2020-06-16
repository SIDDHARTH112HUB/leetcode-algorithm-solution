[1289.minimum-falling-path-sum-ii](https://leetcode.com/problems/minimum-falling-path-sum-ii/)  

Given a square grid of integers `arr`, a _falling path with non-zero shifts_ is a choice of exactly one element from each row of `arr`, such that no two elements chosen in adjacent rows are in the same column.

Return the minimum sum of a falling path with non-zero shifts.

**Example 1:**

  
**Input:** arr = \[\[1,2,3\],\[4,5,6\],\[7,8,9\]\]  
**Output:** 13  
**Explanation: **  
The possible falling paths are:  
\[1,5,9\], \[1,5,7\], \[1,6,7\], \[1,6,8\],  
\[2,4,8\], \[2,4,9\], \[2,6,7\], \[2,6,8\],  
\[3,4,8\], \[3,4,9\], \[3,5,7\], \[3,5,9\]  
The falling path with the smallest sum is \[1,5,7\], so the answer is 13.  

**Constraints:**

*   `1 <= arr.length == arr[i].length <= 200`
*   `-99 <= arr[i][j] <= 99`  



**Solution:**  

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int> > dp(arr.size(), vector<int>(arr[0].size(), INT_MAX));
        for(int i = 0; i < arr[0].size(); ++i) {
            dp[0][i] = arr[0][i];
        }
        for(int i = 1; i < arr.size(); ++i) {
            for(int j = 0;j < arr[0].size(); ++j) {
                for(int k = 0; k < arr[0].size(); ++k){
                    if(k == j) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + arr[i][j]);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
```
      