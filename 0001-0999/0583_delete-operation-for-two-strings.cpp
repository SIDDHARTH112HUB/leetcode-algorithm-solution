//Link: https://leetcode.com/problems/delete-operation-for-two-strings/ 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word2.size()+1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for( int i = 1;  i <= word1.size(); i++ ){
            int prev = 0;
            for( int j = 1; j<=word2.size(); j++){
                int tmp = dp[j];
                if( word1[i-1] == word2[j-1] ){
                    dp[j] = prev+1;
                }else{
                    dp[j] = max(dp[j], dp[j-1]); 
                }
                prev = tmp;
            }
        }
        return word1.size() +word2.size()  - 2* dp[word2.size()];
    }
};