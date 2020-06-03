//Link: https://leetcode.com/problems/number-of-closed-islands/ 
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            if(grid[i][0] == 0)
                dfs(grid, i, 0);
            if(grid[i][n-1] == 0)
                dfs(grid, i, n-1);
        }
        for(int i = 0; i < n; ++i) {
            if(grid[0][i] == 0)
                dfs(grid, 0, i);
            if(grid[m-1][i] == 0)
                dfs(grid, m-1, i);
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        if( x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0) return;
        grid[x][y] = 1;
        dfs(grid, x + 1, y);
        dfs(grid, x, y+1);
        dfs(grid, x - 1, y);
        dfs(grid, x, y-1);
    }
};