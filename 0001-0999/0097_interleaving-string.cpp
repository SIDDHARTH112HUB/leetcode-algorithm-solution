//Link: https://leetcode.com/problems/interleaving-string/ 
class Solution {
public:
    //other
    unordered_map<int, unordered_map<int, int> > m;
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if( m+n != s3.size() ) return false;
        return h(s1, s2, s3, s1.size(), s2.size());
        bool dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for( int i = 1; i<=m; i++ )
            if( dp[i-1][0] && s1[i-1] == s3[i-1] ) dp[i][0] = true;
        for( int i = 1; i<=n; i++ )
            if( dp[0][i-1] && s2[i-1] == s3[i-1] ) dp[0][i] = true;
        for( int i = 1; i<=m;i++){
            for( int j = 1; j<=n; j++){
                if( ( dp[i-1][j] && s1[i-1] == s3[i+j-1]  ) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]) )
                    dp[i][j] = true;
            }
        }
        return dp[m][n];
    }
    
    bool h(string &s1, string&s2, string &s3, int i, int j) {
        if(i == 0 && j == 0) return true;
        if(i < 0 || j < 0) return false;
        if(m[i].count(j)) return m[i][j];
        bool res = false;
        if(i > 0 && s1[i-1] == s3[i+j-1])
            res = res || h(s1, s2, s3, i-1, j);
        if(j > 0 && s2[j-1] == s3[i+j-1])
            res = res || h(s1, s2, s3, i, j-1);
        m[i][j] = res;
        return res;
    }
};