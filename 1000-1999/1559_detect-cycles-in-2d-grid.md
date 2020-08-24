[1559.detect-cycles-in-2d-grid](https://leetcode.com/problems/detect-cycles-in-2d-grid/)  

Given a 2D array of characters `grid` of size `m x n`, you need to find if there exists any cycle consisting of the **same value** in `grid`.

A cycle is a path of **length 4 or more** in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the **same value** of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle `(1, 1) -> (1, 2) -> (1, 1)` is invalid because from `(1, 2)` we visited `(1, 1)` which was the last visited cell.

Return `true` if any cycle of the same value exists in `grid`, otherwise, return `false`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/07/15/1.png)**

  
**Input:** grid = \[\["a","a","a","a"\],\["a","b","b","a"\],\["a","b","b","a"\],\["a","a","a","a"\]\]  
**Output:** true  
**Explanation:** There are two valid cycles shown in different colors in the image below:  
![](https://assets.leetcode.com/uploads/2020/07/15/11.png)  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/07/15/22.png)**

  
**Input:** grid = \[\["c","c","c","a"\],\["c","d","c","c"\],\["c","c","e","c"\],\["f","c","c","c"\]\]  
**Output:** true  
**Explanation:** There is only one valid cycle highlighted in the image below:  
![](https://assets.leetcode.com/uploads/2020/07/15/2.png)  

**Example 3:**

**![](https://assets.leetcode.com/uploads/2020/07/15/3.png)**

  
**Input:** grid = \[\["a","b","b"\],\["b","z","b"\],\["b","b","a"\]\]  
**Output:** false  

**Constraints:**

*   `m == grid.length`
*   `n == grid[i].length`
*   `1 <= m <= 500`
*   `1 <= n <= 500`
*   `grid` consists only of lowercase English letters.  



**Solution:**  

```cpp

class Solution {
public:
    bool vis[500][500];  //for detecting cycle.
    bool vis2[500][500];//avoid to re-visit non-cycle point.
    bool containsCycle(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(dfs(grid, i, j, -1, -1, grid[i][j]))
                    return true;
        return false;
    }
    //px ===> previousX, py =====> previousY
    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py, int c) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != c) return false;
        if(vis[x][y]) return true;   //detecting cycle.
        if(vis2[x][y]) return false;//avoid to re-visit non-cycle point.
        vis[x][y] = true;
        vis2[x][y] = true;
        int d[5] = {0, 1, 0, -1, 0};
        bool res = false;
        for(int i = 0; i < 4; ++i) {
            int nx = d[i] + x;
            int ny = d[i + 1] + y;
            if(nx == px && ny == py) continue; //avoid to go into previous point.
            res |= dfs(grid, nx, ny, x, y, c);
            if(res) break;
        }
        if(res) return true;
        vis[x][y] = false;
        return false;
    }
};

```
      