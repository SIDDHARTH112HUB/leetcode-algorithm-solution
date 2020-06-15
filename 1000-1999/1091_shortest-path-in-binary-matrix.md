[1091.shortest-path-in-binary-matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)  

In an N by N square grid, each cell is either empty (0) or blocked (1).

A _clear path from top-left to bottom-right_ has length `k` if and only if it is composed of cells `C_1, C_2, ..., C_k` such that:

*   Adjacent cells `C_i` and `C_{i+1}` are connected 8-directionally (ie., they are different and share an edge or corner)
*   `C_1` is at location `(0, 0)` (ie. has value `grid[0][0]`)
*   `C_k` is at location `(N-1, N-1)` (ie. has value `grid[N-1][N-1]`)
*   If `C_i` is located at `(r, c)`, then `grid[r][c]` is empty (ie. `grid[r][c] == 0`).

Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

**Example 1:**

**Input:** \[\[0,1\],\[1,0\]\]
![](https://assets.leetcode.com/uploads/2019/08/04/example1_1.png) 
**Output:** 2
![](https://assets.leetcode.com/uploads/2019/08/04/example1_2.png)

**Example 2:**

**Input:** \[\[0,0,0\],\[1,1,0\],\[1,1,0\]\]
![](https://assets.leetcode.com/uploads/2019/08/04/example2_1.png) 
**Output:** 4
![](https://assets.leetcode.com/uploads/2019/08/04/example2_2.png)

**Note:**

1.  `1 <= grid.length == grid[0].length <= 100`
2.  `grid[r][c]` is `0` or `1`  



**Solution:**  

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<int> q;
        if(grid[0][0] == 1) return -1;
        q.push(0);
        unordered_set<int> v;
        v.insert(0);
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0,  1,  1, 1, 0, -1, -1};
        int m = grid.size();
        int step = 1;
        int n = grid[0].size();
        if(grid[m-1][n-1] == 1) return -1;
        while(q.size() > 0){
            int size = q.size();
            while(size-- > 0) {
                int h = q.front();
                q.pop();
                int x = h >> 8;
                int y = h & 0xFF;
                if(x == m-1 && y ==n-1)
                    return step;
                for(int i = 0;i  < 8; i++) {
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 1 || v.count((nx<<8) | ny))
                        continue;
                    int nh = (nx<<8)|ny;
                    q.push(nh);
                    v.insert(nh);
                }
            }
            ++step;
        }
        return -1;
    }
};
```
      