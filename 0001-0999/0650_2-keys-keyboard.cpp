//Link: https://leetcode.com/problems/2-keys-keyboard/ 
class Solution {
public:
    int minSteps(int n) {
        int dp[n+1] = {0};
        dp[1] = 0;
        for( int i = 2; i<=n; i++){
            dp[i] = i;
            for( int j = 2; j<= sqrt(n); j++){
                if( i%j == 0 ){
                    dp[i] = dp[i/j] + j;
                    break;
                }
            }
        }
        return dp[n];
    }
};