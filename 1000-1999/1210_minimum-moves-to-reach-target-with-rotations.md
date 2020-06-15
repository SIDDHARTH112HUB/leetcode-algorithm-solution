[1210.minimum-moves-to-reach-target-with-rotations](https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/)  

In an `n*n` grid, there is a snake that spans 2 cells and starts moving from the top left corner at `(0, 0)` and `(0, 1)`. The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at `(n-1, n-2)` and `(n-1, n-1)`.

In one move the snake can:

*   Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
*   Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
*   Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from `(r, c)` and `(r, c+1)` to `(r, c)` and `(r+1, c)`.  
    ![](https://assets.leetcode.com/uploads/2019/09/24/image-2.png)
*   Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from `(r, c)` and `(r+1, c)` to `(r, c)` and `(r, c+1)`.  
    ![](https://assets.leetcode.com/uploads/2019/09/24/image-1.png)

Return the minimum number of moves to reach the target.

If there is no way to reach the target, return `-1`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/09/24/image.png)**

**Input:** grid = \[\[0,0,0,0,0,1\],
               \[1,1,0,0,1,0\],
               \[0,0,0,0,1,1\],
               \[0,0,1,0,1,0\],
               \[0,1,1,0,0,0\],
               \[0,1,1,0,0,0\]\]
**Output:** 11
**Explanation:** One possible solution is \[right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down\].

**Example 2:**

**Input:** grid = \[\[0,0,1,1,1,1\],
               \[0,0,0,0,1,1\],
               \[1,1,0,0,0,1\],
               \[1,1,1,0,0,1\],
               \[1,1,1,0,0,1\],
               \[1,1,1,0,0,0\]\]
**Output:** 9

**Constraints:**

*   `2 <= n <= 100`
*   `0 <= grid[i][j] <= 1`
*   It is guaranteed that the snake starts at empty cells.  



**Solution:**  

```cpp
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        q.push({0, 0, 0, 1});
        set<vector<int>> v;
        v.insert({0, 0, 0, 1});
        int n = grid.size();
        int step = 0;
        int d[3] = {0, 1, 0};
        while(q.size()){
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                int x0 = p[0], y0 = p[1], x1 = p[2], y1 = p[3];
                q.pop();
                if(x0 == n- 1 && y0 == n - 2 && x1 == n - 1 && y1 == n - 1){
                    return step;
                }
                for(int i = 0; i < 2; ++i) {
                    int nx = x0 + d[i];
                    int ny = y0 + d[i + 1];
                    int nx1 = x1 + d[i];
                    int ny1 = y1 + d[i + 1];
                    if(nx < 0 || ny < 0 || nx >=n || ny >= n || grid[nx][ny] == 1) continue;
                    if(nx1 < 0 || ny1 < 0 || nx1 >=n || ny1 >= n || grid[nx1][ny1] == 1) continue;
                    auto np = {nx, ny, nx1, ny1};
                    if(v.count(np)) continue;
                    v.insert(np);
                    q.push(np);
                }
                if(x1 > x0 && y0 + 1 < n && grid[x0][y0+1] == 0 && grid[x1][y0+1] == 0) {
                    x1 = x0;
                    y1 = y0 + 1;
                }else if(y1 > y0 && x0 + 1 < n && grid[x0 + 1][y0] == 0 && grid[x0+1][y1] == 0) {
                    x1 = x0 + 1;
                    y1 = y0;
                }
                auto np = {x0, y0, x1, y1};
                if(v.count(np) == 0){
                    q.push(np);
                    v.insert(np);
                }
            }
            ++step;
        }
        return -1;
    }
};
```
      