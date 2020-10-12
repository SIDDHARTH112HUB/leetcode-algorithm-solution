[1594.maximum-non-negative-product-in-a-matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/)  

You are given a `rows x cols` matrix `grid`. Initially, you are located at the top-left corner `(0, 0)`, and in each step, you can only **move right or down** in the matrix.

Among all possible paths starting from the top-left corner `(0, 0)` and ending in the bottom-right corner `(rows - 1, cols - 1)`, find the path with the **maximum non-negative product**. The product of a path is the product of all integers in the grid cells visited along the path.

Return the _maximum non-negative product **modulo**_ `109 + 7`. _If the maximum product is **negative** return_ `-1`.

**Notice that the modulo is performed after getting the maximum product.**

**Example 1:**

  
**Input:** grid = \[\[-1,-2,-3\],  
               \[-2,-3,-3\],  
               \[-3,-3,-2\]\]  
**Output:** -1  
**Explanation:** It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.  

**Example 2:**

  
**Input:** grid = \[\[**1**,-2,1\],  
               \[**1**,**\-2**,1\],  
               \[3,**\-4**,**1**\]\]  
**Output:** 8  
**Explanation:** Maximum non-negative product is in bold (1 \* 1 \* -2 \* -4 \* 1 = 8).  

**Example 3:**

  
**Input:** grid = \[\[**1**, 3\],  
               \[**0**,**\-4**\]\]  
**Output:** 0  
**Explanation:** Maximum non-negative product is in bold (1 \* 0 \* -4 = 0).  

**Example 4:**

  
**Input:** grid = \[\[ **1**, 4,4,0\],  
               \[**\-2**, 0,0,1\],  
               \[ **1**,**\-1**,**1**,**1**\]\]  
**Output:** 2  
**Explanation:** Maximum non-negative product is in bold (1 \* -2 \* 1 \* -1 \* 1 \* 1 = 2).  

**Constraints:**

*   `1 <= rows, cols <= 15`
*   `-4 <= grid[i][j] <= 4`  



**Solution:**  

```cpp
class Solution {
public:
    int m;
    int n;
    int maxProductPath(vector<vector<int>>& _grid) {
        m = _grid.size(); n = _grid[0].size();
        vector<vector<long long> > grid(m, vector<long long>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0 ;j < n ; ++j) {
                grid[i][j] = _grid[i][j];
            }
        }
        vector<vector<pair<long long, long long > > > dp(m, vector<pair<long long, long long > >(n, {INT_MAX, INT_MIN} ));
        dp[0][0].first = grid[0][0];
        dp[0][0].second = grid[0][0];
        for(int i = 1; i < m; ++i) {
            dp[i][0].first = grid[i][0] * dp[i - 1][0].first;
            dp[i][0].second = dp[i][0].first;
        }
        for(int i = 1; i < n; ++i) {
            dp[0][i].first = grid[0][i] * dp[0][i - 1].first;
            dp[0][i].second = dp[0][i].first;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1 ;j < n ; ++j) {
                dp[i][j].first = min(dp[i][j].first, grid[i][j] * dp[i - 1][j].first);
                dp[i][j].first = min(dp[i][j].first, grid[i][j] * dp[i][j - 1].first);
                dp[i][j].first = min(dp[i][j].first, grid[i][j] * dp[i - 1][j].second);
                dp[i][j].first = min(dp[i][j].first, grid[i][j] * dp[i][j - 1].second);
                
                dp[i][j].second = max(dp[i][j].second, grid[i][j] * dp[i - 1][j].first);
                dp[i][j].second = max(dp[i][j].second, grid[i][j] * dp[i][j - 1].first);
                dp[i][j].second = max(dp[i][j].second, grid[i][j] * dp[i - 1][j].second);
                dp[i][j].second = max(dp[i][j].second, grid[i][j] * dp[i][j - 1].second);
            }
        }
        long long res = dp[m-1][n-1].second;
        if(res < 0) return -1;
        int M = 1e9 + 7;
        return res % M;
    }
};
```
      