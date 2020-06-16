[361.bomb-enemy](https://leetcode.com/problems/bomb-enemy/)  

Given a 2D grid, each cell is either a wall `'W'`, an enemy `'E'` or empty `'0'` (the number zero), return the maximum enemies you can kill using one bomb.  
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.  
**Note:** You can only put the bomb at an empty cell.

**Example:**

  
**Input:** \[\["0","E","0","0"\],\["E","0","W","E"\],\["0","E","0","0"\]\]
  
**Output:** 3 
  
**Explanation:** For the given grid,
  

  
0 E 0 0 
  
E 0 W E 
  
0 E 0 0
  

  
Placing a bomb at (1,1) kills 3 enemies.  



**Solution:**  

```cpp
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0, rowCnt, colCnt[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowCnt = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; ++k) {
                        rowCnt += grid[i][k] == 'E';
                    }
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colCnt[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; ++k) {
                        colCnt[j] += grid[k][j] == 'E';
                    }
                }
                if (grid[i][j] == '0') {
                    res = max(res, rowCnt + colCnt[j]);
                }
            }
        }
        return res;
    }
};
```
      