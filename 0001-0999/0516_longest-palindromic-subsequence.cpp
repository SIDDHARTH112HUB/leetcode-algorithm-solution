//Link: https://leetcode.com/problems/longest-palindromic-subsequence/ 
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        bool dp[size+1][size+1] ={ 0 };
        int ans = 0;
        for( int i = size-1; i>=0; i-- ){
            for( int j = i; j<size; j++){
                if( s[i] == s[j] && (j-i<=1 || dp[i+1][j-1] )){
                    dp[i][j] = true;
                    ans = max( ans, j-i+1);
                }
            }   
        }
        return ans;
    }
};