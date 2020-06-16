[1293.shortest-path-in-a-grid-with-obstacles-elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)  

Given a `m * n` grid, where each cell is either `0` (empty) or `1` (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner `(0, 0)` to the lower right corner `(m-1, n-1)` given that you can eliminate **at most** `k` obstacles. If it is not possible to find such walk return -1.

**Example 1:**

  
**Input:** 
  
grid = 
  
\[\[0,0,0\],
  
 \[1,1,0\],
  
 \[0,0,0\],
  
 \[0,1,1\],
  
 \[0,0,0\]\], 
  
k = 1
  
**Output:** 6
  
**Explanation:** The shortest path without eliminating any obstacle is 10. 
  
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is `(0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> **(3,2)** -> (4,2)`.
  

**Example 2:**

  
**Input:** 
  
grid = 
  
\[\[0,1,1\],
  
 \[1,1,1\],
  
 \[1,0,0\]\], 
  
k = 1
  
**Output:** -1
  
**Explanation:** We need to eliminate at least two obstacles to find such a walk.
  

**Constraints:**

*   `grid.length == m`
*   `grid[0].length == n`
*   `1 <= m, n <= 40`
*   `1 <= k <= m*n`
*   `grid[i][j] == 0 **or** 1`
*   `grid[0][0] == grid[m-1][n-1] == 0`  



**Solution:**  

```cpp
class Solution {
public:
    int hash(int k, int x, int y) {
        return (k << 16) | (x << 8) | y;
    }
    int shortestPath(vector<vector<int>>& grid, int K) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int> > q;
        map<int, map<int, int > > v;
        q.push({0, 0, 0});
        v[0][0] = 0;
        int step = 0;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto &arr = q.front();
                int k = arr[0], x = arr[1], y = arr[2];
                if(x == m-1 && y == n -1)
                    return step;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + d[i];
                    int ny = y + d[i + 1];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    if(grid[nx][ny] == 1 && k == K) continue;
                    int nk = k+grid[nx][ny];
                    if(v[nx].count(ny)) {
                        if(v[nx][ny] <= nk)
                            continue;
                    }
                    q.push({nk, nx, ny});
                    v[nx][ny] = nk;
                }
                q.pop();
            }
            ++step;
        }
        return -1;
    }
};
```
      