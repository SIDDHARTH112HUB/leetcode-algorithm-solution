//Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/ 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int> > dp(arr.size(), vector<int>(arr[0].size(), INT_MAX));
        for(int i = 0; i < arr[0].size(); ++i) {
            dp[0][i] = arr[0][i];
        }
        for(int i = 1; i < arr.size(); ++i) {
            for(int j = 0;j < arr[0].size(); ++j) {
                for(int k = 0; k < arr[0].size(); ++k){
                    if(k == j) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + arr[i][j]);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};