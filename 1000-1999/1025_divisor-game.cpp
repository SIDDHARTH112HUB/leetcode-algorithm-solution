//Link: https://leetcode.com/problems/divisor-game/ 
class Solution {
public:
    bool divisorGame(int N) {
        int dp[N+2] = {0};
        dp[1] = false;
        dp[2] = true;
        for(int i = 3; i <= N; ++i) {
            int res = false;
            for(int j = 1; j < i; ++j) {
                if(dp[j] == false && i % (i-j) == 0) {
                    res = true;
                    break;
                }
            }
            dp[i] = res;
        }
        return dp[N];
    }
};