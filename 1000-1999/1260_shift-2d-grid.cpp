//Link: https://leetcode.com/problems/shift-2d-grid/ 
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0) return grid;
        vector<vector<int> > ans(grid.size(), vector<int>(grid[0].size()));
        while(k-->0) {
            for(int i = 0; i < grid.size(); ++i) {
                for(int j = 0; j < grid[i].size()-1; ++j) {
                    ans[i][j+1] = grid[i][j];
                }
            }
            for(int j = 0; j < grid.size()-1; ++j) {
                ans[j+1][0] = grid[j].back();
            }
            ans[0][0] = grid.back().back();
            grid = ans;
        }
        return ans;
    }
};