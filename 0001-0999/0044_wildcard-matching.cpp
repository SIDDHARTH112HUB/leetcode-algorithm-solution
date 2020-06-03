//Link: https://leetcode.com/problems/wildcard-matching/ 
class Solution {
public:
    //bool dp[2000];
    
    bool isMatch(string s, string p){
        //memset(dp, true, sizeof(dp));
        //return isMatch2(s, p, 0, 0);
        int dp[s.size()+1][p.size()+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for( int i = 0; i<p.size(); i++){
            if( p[i] == '*')
                dp[0][i+1] = dp[0][i];
        }
        for( int i =1; i<=s.size(); i++){
            for( int j = 1; j<=p.size(); j++){
                if( p[j-1] == '*')
                    dp[i][j] = dp[i][j-1]|| dp[i-1][j];
                else
                    dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='?') && dp[i-1][j-1];
            }
        }
        return dp[s.size()][p.size()];
    }
    /*bool isMatch2(string &s, string &p, int si, int pi) {
        if( dp[si] == false) return false;
        
        while( si < s.size() || pi < p.size() ){
            if( si == s.size() && p[pi] != '*')
                return false;
            if( pi == p.size() && si <s.size() )
                return false;
            if( p[pi]=='?' || s[si] == p[pi] ){
                si++;
                pi++;
            }else if( p[pi] == '*'){
                for( int i = si; i<=s.size(); i++){
                    bool res = isMatch2(s, p, i, pi+1);
                    if( res == true )
                        return true;
                    dp[i] = false;
                }
                return false;
            }else
                return false;
        }
        return true;
    }*/
    
};