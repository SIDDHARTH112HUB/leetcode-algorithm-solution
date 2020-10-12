[1568.minimum-number-of-days-to-disconnect-island](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/)  

Given a 2D `grid` consisting of `1`s (land) and `0`s (water).  An _island_ is a maximal 4-directionally (horizontal or vertical) connected group of `1`s.

The grid is said to be **connected** if we have **exactly one island**, otherwise is said **disconnected**.

In one day, we are allowed to change **any** single land cell `(1)` into a water cell `(0)`.

Return _the minimum number of days_ to disconnect the grid.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/08/13/1926_island.png)**

  
**Input:** grid = \[\[0,1,1,0\],\[0,1,1,0\],\[0,0,0,0\]\]  
**Output:** 2  
**Explanation:** We need at least 2 days to get a disconnected grid.  
Change land grid\[1\]\[1\] and grid\[0\]\[2\] to water and get 2 disconnected island.  

**Example 2:**

  
**Input:** grid = \[\[1,1\]\]  
**Output:** 2  
**Explanation:** Grid of full water is also disconnected (\[\[1,1\]\] -> \[\[0,0\]\]), 0 islands.  

**Example 3:**

  
**Input:** grid = \[\[1,0,1,0\]\]  
**Output:** 0  

**Example 4:**

  
**Input:** grid = \[\[1,1,0,1,1\],  
               \[1,1,1,1,1\],  
               \[1,1,0,1,1\],  
               \[1,1,0,1,1\]\]  
**Output:** 1  

**Example 5:**

  
**Input:** grid = \[\[1,1,0,1,1\],  
               \[1,1,1,1,1\],  
               \[1,1,0,1,1\],  
               \[1,1,1,1,1\]\]  
**Output:** 2  

**Constraints:**

*   `1 <= grid.length, grid[i].length <= 30`
*   `grid[i][j]` is `0` or `1`.  



**Solution:**  

```cpp
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1) return;
        grid[x][y] = 0;
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
    }
    int count(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
    int check(vector<vector<int>>& grid) {
        auto org = grid;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if(count(grid) > 1) return true;
                    grid = org;
                }
            }
        }
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        auto org = grid;
        int d[5] = {0, 1, 0, -1, 0};
        int mx = 5;
        int m = grid.size(), n = grid[0].size();
        int co = 0;
        if(count(grid) == 1) {
            grid = org;
            if(check(grid)) return 1;
            return 2;
        }
        return 0;
    }
};
```
      