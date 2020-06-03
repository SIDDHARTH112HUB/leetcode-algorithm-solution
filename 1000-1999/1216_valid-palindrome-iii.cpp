//Link: https://leetcode.com/problems/valid-palindrome-iii/ 
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int dp[s.size() + 1][s.size() + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
            for(int j = i-1; j >=0; --j){
                if(s[i] == s[j]){
                    dp[j][i] = dp[j+1][i-1] + 2;
                }else{
                    dp[j][i] = max(dp[j][i-1], dp[j+1][i]);
                }
            }
        }
        return s.size() <= dp[0][s.size()-1] +k;
    }
};