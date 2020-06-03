//Link: https://leetcode.com/problems/student-attendance-record-ii/ 
class Solution {
public:
    int checkRecord(int n) {
        long long dp[n+5] = {0};
        long long M = 1000000007;
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        dp[3] = 7;
        for(int i = 4; i <= n; ++i) {
            dp[i] += dp[i-1] % M;
            dp[i] += (dp[i-1] + (M- dp[i-4]) % M) %M;
        }
        for(int i = 0; i < n ;++i) {
            dp[n] += (dp[i] * dp[n-i-1]) %M;
        }
        return dp[n] % M;
    }
};