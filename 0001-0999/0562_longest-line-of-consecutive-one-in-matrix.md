[562.longest-line-of-consecutive-one-in-matrix](https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/)  

Given a 01 matrix **M**, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

**Example:**  

**Input:**
\[\[0,1,1,0\],
 \[0,1,1,0\],
 \[0,0,0,1\]\]
**Output:** 3

**Hint:** The number of elements in the given matrix will not exceed 10,000.  



**Solution:**  

```cpp
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size(), res = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 0) continue;
                for (int k = 0; k < 4; ++k) dp[i][j][k] = 1;
                if (j > 0) dp[i][j][0] += dp[i][j - 1][0]; // horizonal
                if (i > 0) dp[i][j][1] += dp[i - 1][j][1]; // vertical
                if (i > 0 && j < n - 1) dp[i][j][2] += dp[i - 1][j + 1][2]; // diagonal
                if (i > 0 && j > 0) dp[i][j][3] += dp[i - 1][j - 1][3]; // anti-diagonal
                res = max(res, max(dp[i][j][0], dp[i][j][1]));
                res = max(res, max(dp[i][j][2], dp[i][j][3]));
            }
        }
        return res;
    }
};
```
      