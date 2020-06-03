//Link: https://leetcode.com/problems/paint-house-ii/ 
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int houseSize = costs.size();
        if(houseSize == 0) return 0;
        int colSize = costs[0].size();
        if(colSize == 0) return 0;
        vector<vector<int> > dp(houseSize, vector<int>(colSize, INT_MAX));
        for(int i = 0; i < houseSize; ++i){
            for(int j = 0; j < colSize; ++j) {
                if(i == 0) {
                    dp[i][j] = costs[i][j];
                    continue;
                }
                for(int k = 0; k < colSize; ++k) {
                    if(k == j) continue;
                    dp[i][k] = min(dp[i][k], dp[i-1][j] + costs[i][k]);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};