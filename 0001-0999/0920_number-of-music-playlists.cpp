//Link: https://leetcode.com/problems/number-of-music-playlists/ 
class Solution {
public:
    int M = 1000000007;
    int numMusicPlaylists(int N, int L, int K) {
        long long dp[N+1][L+1];
        for( int i = K+1; i<=N; i++){
            for( int j = i; j<=L; j++){
                if( i == j || i == K+1){
                    dp[i][j] = fac(i);
                }else{
                    dp[i][j] = (dp[i-1][j-1] * i  + dp[i][j-1]*(i-K))%M;
                }
            }
        }
        return dp[N][L];
    }
    long long fac(long long i){
        return i ? fac(i-1)*i % M : 1;
    }
};