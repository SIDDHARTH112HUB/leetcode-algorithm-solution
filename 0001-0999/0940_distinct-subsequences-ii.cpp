//Link: https://leetcode.com/problems/distinct-subsequences-ii/ 
class Solution {
public:
    int distinctSubseqII(string S) {
        int dp[S.size()+1] = {0};
        dp[0] = 1;
        int last[256];
        int M = 1000000007;
        for( int i = 0; i<256;i++)
            last[i] = -1;
        for( int i = 1; i<=S.size(); i++ ){
            dp[i] = (2 * dp[i-1] )% M;
            char c = S[i-1];
            if( last[c] != -1 )
                dp[i] = ((dp[i] + M) - dp[last[c]])%M;
            last[c] = i-1;
        }
        return dp[S.size()]-1;
    }
};