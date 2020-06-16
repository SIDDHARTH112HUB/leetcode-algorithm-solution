[994.rotting-oranges](https://leetcode.com/problems/rotting-oranges/)  

In a given grid, each cell can have one of three values:

*   the value `0` representing an empty cell;
*   the value `1` representing a fresh orange;
*   the value `2` representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return `-1` instead.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/02/16/oranges.png)**

  
**Input:** \[\[2,1,1\],\[1,1,0\],\[0,1,1\]\]
  
**Output:** 4
  

**Example 2:**

  
**Input:** \[\[2,1,1\],\[0,1,1\],\[1,0,1\]\]
  
**Output:** \-1
  
**Explanation: ** The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
  

**Example 3:**

  
**Input:** \[\[0,2\]\]
  
**Output:** 0
  
**Explanation: ** Since there are already no fresh oranges at minute 0, the answer is just 0.
  

**Note:**

1.  `1 <= grid.length <= 10`
2.  `1 <= grid[0].length <= 10`
3.  `grid[i][j]` is only `0`, `1`, or `2`.  



**Solution:**  

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int> > q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for( int i= 0; i< m; i++){
            for( int j = 0; j < n; j++ ){
                if( grid[i][j] == 2 )
                    q.push({i, j });
                if( grid[i][j] == 1 )
                    ++fresh;
            }
        }
        int ans = 0 ;
        if( fresh == 0 )
            return 0;
        while( q.size() > 0 ){
            int size = q.size();
            int r = 0;
            while( size-- > 0 ){
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                int d[5] = {0, 1, 0, -1, 0};
                for( int i = 0; i < 4; i++){
                    int nx = x + d[i];
                    int ny = y + d[i+1];
                    if( nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1 )
                        continue;
                    ++r;
                    --fresh;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            ans += r>0?1:0;
        }
        return fresh>0?-1:ans;
    }
};
```
      