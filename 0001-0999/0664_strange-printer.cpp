//Link: https://leetcode.com/problems/strange-printer/ 
class Solution {
public:
    int strangePrinter(string s) {
        if(s.size() == 0 ) return 0;
        int dp[100][100] = {0};
        return helper(s, 0, s.size()-1, dp);
    }
    
    int helper(string &s, int i, int j, int dp[100][100]) {
        if(i > j) return 0;
        if(dp[i][j]) return dp[i][j];
        int res = 1 + helper(s, i + 1, j, dp);
        for(int k = i + 1; k <=j; k++) {
            if(s[k] == s[i])
                res = min(res, helper(s, i + 1, k-1, dp) + helper(s, k, j, dp));
        }
        dp[i][j] = res;
        return res;
    }
};