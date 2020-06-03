//Link: https://leetcode.com/problems/champagne-tower/ 
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[query_row+1] = {0};
        memset(dp, 0, sizeof(dp));
        dp[0] = poured;
        for(int i = 1; i <= query_row; ++i) {
            for(int j = i; j >= 0; --j) {
                double l =  j > 0 ? (dp[j - 1] - 1) / 2 : 0;
                double r = (dp[j] - 1) / 2;
                dp[j] = (l > 0 ? l : 0) +  (r > 0 ? r : 0);
            }
        }
        return min(1.0, dp[query_glass]);
    }
};