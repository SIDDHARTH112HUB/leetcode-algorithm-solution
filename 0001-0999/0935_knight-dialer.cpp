//Link: https://leetcode.com/problems/knight-dialer/ 
class Solution {
public:
    int knightDialer(int N) {
        int dp[N][10] = {0};
        for( int i = 0; i<10; i++){
            dp[0][i] = 1;
        }
        int M = 1000000007;
        unordered_map<int, vector<int> > m;
        m[0] = {4, 6};
        m[1] = {8, 6};
        m[2] = {7, 9};
        m[3] = {4, 8};
        m[4] = {0, 9, 3};
        m[6] = {1, 7, 0};
        m[7] = {2, 6};
        m[8] = {1, 3};
        m[9] = {4, 2};
        if( N == 1 ) return 10;
        for( int n = 1; n < N; n++){
            for( int i = 0; i<10; i++){
                if( i == 5 )continue;
                for( int t : m[i]){
                    dp[n][i] += dp[n-1][t];
                    dp[n][i] %= M;
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < 10; i++){
            ans += dp[N-1][i];
            ans %= M;
        }
        return ans;
    }
};