//Link: https://leetcode.com/problems/path-with-maximum-gold/ 
class Solution {
public:
    set<pair<int, int> > v;
    int ans = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] > 0) {
                    helper(grid, i, j , 0);
                }
            }
        }
        return ans;
    }
    
    void helper(vector<vector<int>>& grid, int x, int y, int gold) {
        if(v.count({x, y})) return;
        int m = grid.size();
        int n = grid[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0) return;
        ans = max(ans, gold + grid[x][y]);
        v.insert({x, y});
        int ng = gold + grid[x][y];
        helper(grid, x + 1, y, ng);
        helper(grid, x - 1, y, ng);
        helper(grid, x , y + 1, ng);
        helper(grid, x , y - 1, ng);
        v.erase({x, y});
    }
};