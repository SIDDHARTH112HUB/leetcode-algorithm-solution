[1162.as-far-from-land-as-possible](https://leetcode.com/problems/as-far-from-land-as-possible/)  

Given an N x N `grid` containing only values `0` and `1`, where `0` represents water and `1` represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the _Manhattan distance_: the distance between two cells `(x0, y0)` and `(x1, y1)` is `|x0 - x1| + |y0 - y1|`.

If no land or water exists in the grid, return `-1`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/05/03/1336_ex1.JPG)**

  
**Input:** \[\[1,0,1\],\[0,0,0\],\[1,0,1\]\]  
**Output:** 2  
**Explanation: **  
The cell (1, 1) is as far as possible from all the land with distance 2.  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/05/03/1336_ex2.JPG)**

  
**Input:** \[\[1,0,0\],\[0,0,0\],\[0,0,0\]\]  
**Output:** 4  
**Explanation: **  
The cell (2, 2) is as far as possible from all the land with distance 4.  

**Note:**

1.  `1 <= grid.length == grid[0].length <= 100`
2.  `grid[i][j]` is `0` or `1`  



**Solution:**  

```cpp

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<pair<int, int > > v;
        int ans = 0;
        queue<pair<int, int > > q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) continue;
                q.push({i, j});
                v.insert({i, j});
            }
        }
        int d[5] = {0, 1, 0, -1, 0};
        int step = 0;
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                int x = p.first;
                int y = p.second;
                q.pop();
                for(int k = 0; k < 4; ++k) {
                    int nx = x + d[k];
                    int ny = y + d[k+1];
                    if(nx < 0 || ny < 0 || nx >=m || ny >=n || grid[nx][ny] == 1 || v.count({nx, ny}))continue;
                    v.insert({nx, ny});
                    q.push({nx, ny});
                }
            }
            ++step;
        }
        return step - 1 == 0 ? -1 : step - 1;
    }
};

```
      