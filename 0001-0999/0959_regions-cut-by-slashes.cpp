//Link: https://leetcode.com/problems/regions-cut-by-slashes/ 
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int> > g(n*3, vector<int>(n*3));
        for( int i = 0; i< n ; i++){
            for( int j = 0; j < n ; j++){
                if( grid[i][j] == '\\'){
                    g[i*3][j*3] = -1;
                    g[i*3+1][j*3+1] = -1;
                    g[i*3+2][j*3+2] = -1;
                }else if( grid[i][j] == '/'){
                    g[i*3+2][j*3] = -1;
                    g[i*3+1][j*3+1] = -1;
                    g[i*3][j*3+2] = -1;
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < g.size(); i++){
            for( int j = 0; j < g.size(); j++){
                if( g[i][j] == 0 ){
                    dfs( g, i, j);
                    ++ans;
                }
            }
        }
        
        return ans;
    }
    
    void dfs( vector<vector<int> > &g, int x, int y){
        g[x][y] = -1;
        int d[5] = {0,1,0,-1,0};
        for( int i = 0; i< 4; i++){
            int nx = d[i] +x;
            int ny = d[i+1]+y;
            if( nx < 0 || ny < 0 || nx >= g.size() || ny >= g.size() || g[nx][ny] == -1 )
                continue;
            dfs( g, nx, ny);
        }
    }
};