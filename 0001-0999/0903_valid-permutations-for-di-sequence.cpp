//Link: https://leetcode.com/problems/valid-permutations-for-di-sequence/ 
class Solution {
public:
    int numPermsDISequence(string S) {
        int M = 1000000007;
        int N = S.size();
        long long dp[N+1][N+1] = {0};
        dp[0][0] = 1;
        for( int i = 1; i<=N; i++){
            for( int j = 0; j<=i; j++){
                if( S[i-1] == 'D'){
                    for( int k = j; k <= i-1; k++){
                        dp[i][j] += dp[i-1][k];
                    }
                }else{
                    for( int k = 0; k<j; k++){
                        dp[i][j]+= dp[i-1][k];
                    }
                }
                dp[i][j] %= M;
            }
            
        }
        long long res = 0;
        for( int i = 0; i<=N; i++)
            res = (res + dp[N][i])%M;
        return res;
    }
};