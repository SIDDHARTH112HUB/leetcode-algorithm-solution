[200.number-of-islands](https://leetcode.com/problems/number-of-islands/)  

Given a 2d grid map of `'1'`s (land) and `'0'`s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

  
**Input:**
  
11110
  
11010
  
11000
  
00000
  

  
**Output:** 1
  

**Example 2:**

  
**Input:**
  
11000
  
11000
  
00100
  
00011
  

  
**Output:** 3  



**Solution:**  

```cpp
class Solution {
public:
    int n, m;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if( n == 0 ) return 0;
        m = grid[0].size();
        if( m == 0 ) return 0;
        int ans = 0;
        for( int i = 0; i<n; i++){
            for( int j = 0; j<m; j++){
                if( grid[i][j] == '1'){
                    dfs( grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int x, int y){
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        grid[x][y] = 0;
        for( int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1' ){
                dfs( grid, nx, ny);
            }
        }
    }
};
```
      