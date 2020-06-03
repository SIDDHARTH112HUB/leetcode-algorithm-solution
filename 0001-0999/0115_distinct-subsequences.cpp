//Link: https://leetcode.com/problems/distinct-subsequences/ 
class Solution {
public:
    int numDistinct(string s, string t) {
        
        int dp[t.size()+1][s.size()+1];
        memset(dp, 0, sizeof(dp));
        for( int i = 0; i<=s.size(); i++){
            dp[0][i] = 1;
        }
        for( int i = 1; i<=t.size(); i++ ){
            for( int j= 1; j <= s.size(); j++){
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1]:0);
            }
        }
        return dp[t.size()][s.size()];
    }
    
    /*
    unordered_map<int, unordered_map<int, int> > m;
    int numDistinct(string s, string t) {
        if( t.size() == 0 ) return;
        numDistinct(s.substr(1), t)
    }*/
};