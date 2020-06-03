//Link: https://leetcode.com/problems/number-of-corner-rectangles/ 
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m - 1; ++i) {
            vector<int> ones;
            for(int k = 0; k < n; ++k) if(grid[i][k]) ones.push_back(k);
            for(int j = i + 1; j < m; ++j) {
                int cnt = 0;
                for(int k = 0; k < ones.size(); ++k) {
                    if(grid[j][ones[k]]) ++cnt;
                }
                ans += cnt * (cnt - 1) / 2;
            }
        }
        return ans;
    }
};
