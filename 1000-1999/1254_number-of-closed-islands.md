[1254.number-of-closed-islands](https://leetcode.com/problems/number-of-closed-islands/)  

Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An _island_ is a maximal 4-directionally connected group of `0s` and a _closed island_ is an island **totally** (all left, top, right, bottom) surrounded by `1s.`

Return the number of _closed islands_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png)

  
**Input:** grid = \[\[1,1,1,1,1,1,1,0\],\[1,0,0,0,0,1,1,0\],\[1,0,1,0,1,1,1,0\],\[1,0,0,0,0,1,0,1\],\[1,1,1,1,1,1,1,0\]\]
  
**Output:** 2
  
**Explanation:** 
  
Islands in gray are closed because they are completely surrounded by water (group of 1s).

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/10/31/sample_4_1610.png)

  
**Input:** grid = \[\[0,0,1,0,0\],\[0,1,0,1,0\],\[0,1,1,1,0\]\]
  
**Output:** 1
  

**Example 3:**

  
**Input:** grid = \[\[1,1,1,1,1,1,1\],
  
               \[1,0,0,0,0,0,1\],
  
               \[1,0,1,1,1,0,1\],
  
               \[1,0,1,0,1,0,1\],
  
               \[1,0,1,1,1,0,1\],
  
               \[1,0,0,0,0,0,1\],
  
               \[1,1,1,1,1,1,1\]\]
  
**Output:** 2
  

**Constraints:**

*   `1 <= grid.length, grid[0].length <= 100`
*   `0 <= grid[i][j] <=1`  



**Solution:**  

```cpp
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            if(grid[i][0] == 0)
                dfs(grid, i, 0);
            if(grid[i][n-1] == 0)
                dfs(grid, i, n-1);
        }
        for(int i = 0; i < n; ++i) {
            if(grid[0][i] == 0)
                dfs(grid, 0, i);
            if(grid[m-1][i] == 0)
                dfs(grid, m-1, i);
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        if( x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0) return;
        grid[x][y] = 1;
        dfs(grid, x + 1, y);
        dfs(grid, x, y+1);
        dfs(grid, x - 1, y);
        dfs(grid, x, y-1);
    }
};
```
      