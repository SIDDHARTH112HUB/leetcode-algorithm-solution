//Link: https://leetcode.com/problems/k-inverse-pairs-array/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > memo;
    int kInversePairs(int n, int k) {
        //return dfs(n, k);
        int dp[n+1][k+1] = {0};
        //dp[1][1] = 1;
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        int M = 1000000007;
        //for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i][0] = 1;
            int sum = 1;
            for(int m = 1; m <= k; ++m) {
                if(m >= i) sum -= dp[i-1][m-i];
                if(sum < 0) sum = (sum + M) %M;
                (sum += dp[i-1][m]) %= M;
                dp[i][m] += sum;
            }
        }
        return dp[n][k];
    }
    int dfs(int n, int k){
        if(k == 0) return 1;
        if(n == 1) return 1;
        if(memo[n].count(k)) return memo[n][k];
        int res = 0;
        for(int i = 0; i <= min(k, n); i++) {
            res += dfs(n-1, i) + min(k, n) - i;
        }
        memo[n][k] = res;
        return res;
    }
};