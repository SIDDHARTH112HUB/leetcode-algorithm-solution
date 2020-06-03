//Link: https://leetcode.com/problems/count-vowels-permutation/ 
//ae      0
//ea ei   1
//!ii     2
//oi ou   3
//ua      4

class Solution {
public:
    int countVowelPermutation(int n) {
        long long dp[n+1][5];
        long long M = 1000000007;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 1;
        dp[0][4] = 1;
        for(int i = 1; i < n; ++i) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % M;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4])%M;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4])%M;
            dp[i][4] = dp[i-1][0];
        }
        long long ans = 0;
        for(int i = 0; i < 5; ++i)
            ans = (ans + dp[n-1][i])%M;
        return ans;
    }
};