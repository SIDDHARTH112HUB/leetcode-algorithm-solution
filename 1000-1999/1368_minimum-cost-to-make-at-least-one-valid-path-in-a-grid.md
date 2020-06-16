[1368.minimum-cost-to-make-at-least-one-valid-path-in-a-grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)  

Given a _m_ x _n_ `grid`. Each cell of the `grid` has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of `grid[i][j]` can be:

*   **1** which means go to the cell to the right. (i.e go from `grid[i][j]` to `grid[i][j + 1]`)
*   **2** which means go to the cell to the left. (i.e go from `grid[i][j]` to `grid[i][j - 1]`)
*   **3** which means go to the lower cell. (i.e go from `grid[i][j]` to `grid[i + 1][j]`)
*   **4** which means go to the upper cell. (i.e go from `grid[i][j]` to `grid[i - 1][j]`)

Notice that there could be some **invalid signs** on the cells of the `grid` which points outside the `grid`.

You will initially start at the upper left cell `(0,0)`. A valid path in the grid is a path which starts from the upper left cell `(0,0)` and ends at the bottom-right cell `(m - 1, n - 1)` following the signs on the grid. The valid path **doesn't have to be the shortest**.

You can modify the sign on a cell with `cost = 1`. You can modify the sign on a cell **one time only**.

Return _the minimum cost_ to make the grid have at least one valid path.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/02/13/grid1.png)

  
**Input:** grid = \[\[1,1,1,1\],\[2,2,2,2\],\[1,1,1,1\],\[2,2,2,2\]\]  
**Output:** 3  
**Explanation:** You will start at point (0, 0).  
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)  
The total cost = 3.  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/02/13/grid2.png)

  
**Input:** grid = \[\[1,1,3\],\[3,2,2\],\[1,1,4\]\]  
**Output:** 0  
**Explanation:** You can follow the path from (0, 0) to (2, 2).  

**Example 3:**

![](https://assets.leetcode.com/uploads/2020/02/13/grid3.png)

  
**Input:** grid = \[\[1,2\],\[4,3\]\]  
**Output:** 1  

**Example 4:**

  
**Input:** grid = \[\[2,2,2\],\[2,2,2\]\]  
**Output:** 3  

**Example 5:**

  
**Input:** grid = \[\[4\]\]  
**Output:** 0  

**Constraints:**

*   `m == grid.length`
*   `n == grid[i].length`
*   `1 <= m, n <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    int hash(int x, int y) {
       // cout<<x<<" "<<y<<endl;
        return (x <<8) | y;
    }
    void dehash(int v, int &x, int &y) {
        x = (v >> 8);
        y = (v & 0xff);
    }
    int minCost(vector<vector<int>>& grid) {
        map<int, int> seen;
        queue<int> q;
        q.push(0);
        seen[0] = 0;
        int ans = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                int x, y;
                auto h = q.front();q.pop();
                dehash(h, x, y);
                for(int i = 0; i <4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx <0  || ny <0 || nx >= grid.size() || ny >= grid[0].size()) continue;
                    int nh = hash(nx, ny);
                    int addmove = grid[x][y] != i + 1;
                    if(seen.count(nh) && seen[nh] <= seen[h] + addmove) continue;
                    seen[nh] = seen[h] + addmove;
                    q.push(nh);
                }
            }
        }
        int lh = hash(grid.size() - 1, grid[0].size() - 1);
        return seen[lh];
    }
};
```
      