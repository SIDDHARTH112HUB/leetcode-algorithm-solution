//Link: https://leetcode.com/problems/profitable-schemes/ 
class Solution {
public:
    
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int M = 1000000007;
        long long dp[G+1][P+1] = {0};
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for( int i = 0; i<group.size(); i++){
            int g = group[i];
            int p = profit[i];
            for( int k = G-g; k >=0; k--){
                for( int j = P; j>=0; j--){
                    dp[k+g][j] += dp[k][max(j-p,0)];
                    dp[k+g][j] %= M;
                }
            }
        }
        long long ans = 0;
        for( int i = 1; i<= G; i++){
            ans += dp[i][P];
            ans %= M;
        }
        return ans;
    }
};