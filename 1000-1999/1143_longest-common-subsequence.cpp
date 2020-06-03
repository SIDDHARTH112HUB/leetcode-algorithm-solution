//Link: https://leetcode.com/problems/longest-common-subsequence/ 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text2.size()+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= text1.size(); ++i){
            int prev = 0;
            for(int j = 1; j <= text2.size(); ++j) {
                int a = text1[i-1];
                int b = text2[j-1];
                int t = dp[j];
                if (a == b) {
                    dp[j] = prev + 1;
                }else{
                    dp[j] = max(dp[j-1], dp[j]);
                }
                prev = t;
            }
        }
        return dp[text2.size()];
    }
};