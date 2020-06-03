//Link: https://leetcode.com/problems/edit-distance/ 
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int dp[word1.size()+1][word2.size()+1];
        memset(dp, 0 , sizeof(dp));
        for( int i = 0; i<=word1.size(); i++ ){
            dp[i][0] = i;
        }
        
        for( int i = 0; i<=word2.size(); i++ )
            dp[0][i] = i;

        for( int i = 0; i<word1.size(); i++){
            for( int j =0; j<word2.size(); j++){
                if( word1[i] == word2[j] )
                    dp[i+1][j+1] = dp[i][j];
                else{
                    dp[i+1][j+1] = min(min(dp[i][j+1]+1, dp[i+1][j]+1), dp[i][j]+1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
    
};