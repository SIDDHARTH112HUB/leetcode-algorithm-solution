//Link: https://leetcode.com/problems/cherry-pickup-ii/ 
class Solution {
public:
    int dp[72][72][72];
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0, n - 1);
    }
    
    int dfs(vector<vector<int>>& grid, int i, int l, int r) {
        if(l == r) return 0;
        if(i >= grid.size()) return 0;
        if(l < 0 || r < 0 || l >= grid[0].size() || r >= grid[0].size()) return 0;
        int d[3] = {-1, 0, 1};
        // cout<<"xxx"<<endl;
        if(dp[i][l][r] >= 0) return dp[i][l][r];
        // cout<<"xxx"<<endl;
        int res = 0;
        for(int x = 0; x < 3; ++x) {
            for(int y = 0; y < 3; ++y) {
                // cout<<grid[i][l]<<" "<<grid[i][r]<<endl;
                res = max(res, grid[i][l] + grid[i][r] + dfs(grid, i + 1, l + d[x], r + d[y]));
            }
        }
        return dp[i][l][r] = res;
    }
};