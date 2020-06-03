//Link: https://leetcode.com/problems/word-break/ 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int dp[s.size()+1] = {0};
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            if( dict.count(s.substr(0, i) ) ){
                dp[i] = true;
                continue;
            }
            for( int j = 0; j<i; j++){
                if( dp[j] && dict.count( s.substr( j, i-j ) ) ){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};