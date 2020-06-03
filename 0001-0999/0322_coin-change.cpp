//Link: https://leetcode.com/problems/coin-change/ 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i<coins.size(); i++){
            if( coins[i] > amount )
                continue;
            for( int j=0;j<=amount; j++){
                if(j + coins[i] <= amount && dp[j] >= 0){
                    if( dp[j+coins[i]] > 0 )
                        dp[j+coins[i]] = min(dp[j]+1, dp[j+coins[i]]);
                    else
                        dp[j+coins[i]] = dp[j] + 1;
                }
            }
        }
        return dp[amount];
    }
};