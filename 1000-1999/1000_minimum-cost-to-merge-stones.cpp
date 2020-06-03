//Link: https://leetcode.com/problems/minimum-cost-to-merge-stones/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > m;
    int mergeStones(vector<int>& stones, int K) {
        
        int n = stones.size();
        if((n-1) % (K-1) != 0) return -1;
        int dp[n][n];
        int mx = 1000000;
        memset(dp, 8, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1; i < n; ++i) {
            dp[i][i] = 0;
            stones[i] += stones[i-1];
        }
        return dfs(stones, K, 0, n-1);
        for(int l = 2; l <= n; ++l) {
            for(int i = 0; i + l <= n; ++i) {
                int j = i + l - 1;
                for(int m = i; m <j; m+=K-1)
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j]);
                
                if((l-1) % (K-1) == 0){
                    dp[i][j] = dp[i][j] + stones[j] - (i > 0?stones[i-1]:0);
                }
            }
        }
        return dp[0][n-1];
    }
    
    int dfs(vector<int>& stones, int K, int i, int j) {
        int l = j - i + 1;
        //if(l < K) return 0;
        if( i == j) return 0;
        if(m[i].count(j)) return m[i][j];
        
        int res = INT_MAX;
        for(int k = i; k <j; k += K-1) {
            res = min(res, dfs(stones, K, i, k) + dfs(stones, K, k+1, j));
        }
        if((l - 1) % (K-1) == 0){
            res += stones[j] - (i > 0?stones[i-1]:0);
            
        }
        return m[i][j] = res;
    }
};