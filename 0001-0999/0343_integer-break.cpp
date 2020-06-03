//Link: https://leetcode.com/problems/integer-break/ 
class Solution {
public:
    map<int, int> dp;
    int integerBreak(int n,int begin=1) {
        int dp[n+5] = {0};
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        for( int i = 5; i<=n; i++){
            for( int j = 1; j<i; j++){
                dp[i] = max(max(dp[i-j],i-j) * max(dp[j],j), dp[i]);
            }
        }
        return dp[n];
    }
};