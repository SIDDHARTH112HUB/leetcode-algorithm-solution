//Link: https://leetcode.com/problems/palindrome-partitioning-ii/ 
class Solution {
public:
    int minCut(string s) {
        
        int size = s.size();
        vector< vector<bool > > P(size+1, vector<bool>(size+1));
        vector< int > dp(size+1);
        for( int i = 0; i<=size; i++)
            dp[i] = size-i-1;
        for( int i = size-1; i>=0; i--){
            for( int j = i; j<size; j++ ){
                if( s[i] == s[j] && (j-i <= 1 || P[i+1][j-1] ) ){
                    P[i][j] = true;
                    dp[i] = min(dp[i], dp[j+1]+1 );
                }
            }
        }
        return dp[0];
    }
};