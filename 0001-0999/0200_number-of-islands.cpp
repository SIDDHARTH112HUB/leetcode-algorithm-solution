//Link: https://leetcode.com/problems/number-of-islands/ 
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