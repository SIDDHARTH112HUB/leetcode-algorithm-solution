//Link: https://leetcode.com/problems/out-of-boundary-paths/ 
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int M = 1000000007;
        int dp[51][51][51]={0};
        dp[i][j][0] = 1;
        int ans = 0;
        for( int k = 1; k<=N; k++){
            for( int i = 0; i<m;i++){
                for( int j = 0; j<n;j++){
                    int dx[] = {1,-1,0,0};
                    int dy[] = {0,0,1,-1};
                    for( int l = 0; l<4; l++){
                        int nx = i+dx[l];
                        int ny = j+dy[l];
                        if( nx >= 0 && ny >=0 && nx <m && ny < n ){
                            dp[nx][ny][k] = (dp[i][j][k-1] + dp[nx][ny][k])%M;
                        }else{
                            ans = ( ans + dp[i][j][k-1] )%M;
                        }
                    }
                }
            }
        }
        return ans;
    }
};