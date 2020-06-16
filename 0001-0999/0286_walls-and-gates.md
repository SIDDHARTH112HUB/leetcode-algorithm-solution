[286.walls-and-gates](https://leetcode.com/problems/walls-and-gates/)  

You are given a _m x n_ 2D grid initialized with these three possible values.

1.  `-1` - A wall or an obstacle.
2.  `0` - A gate.
3.  `INF` - Infinity means an empty room. We use the value `231 - 1 = 2147483647` to represent `INF` as you may assume that the distance to a gate is less than `2147483647`.

Fill each empty room with the distance to its _nearest_ gate. If it is impossible to reach a gate, it should be filled with `INF`.

**Example:** 

Given the 2D grid:

  
INF  -1  0  INF
  
INF INF INF  -1
  
INF  -1 INF  -1
  
  0  -1 INF INF
  

After running your function, the 2D grid should be:

  
  3  -1   0   1
  
  2   2   1  -1
  
  1  -1   2  -1
  
  0  -1   3   4  



**Solution:**  

```cpp
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(); 
        if(m == 0) return;
        int n = rooms[0].size();
        if(n == 0) return;
        queue<pair<int, int> > q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int step = 1;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size--) {
                auto p = q.front(); q.pop();
                int x = p.first, y = p.second;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + d[i];
                    int ny = y + d[i + 1];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || rooms[nx][ny] != INT_MAX) continue;
                    rooms[nx][ny] = step;
                    q.push({nx, ny});
                }
            }
            ++step;
        }
    }
};
```
      