//Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/ 
class Solution {
public:
    int dp[5001][4][4][4] = {};
    int numOfWays(int n) {
        return dfs(n, 0, 0, 0);
    }
    
    int dfs(int n, int a, int b, int c) {
        if(n == 0) return 1;
        if(dp[n][a][b][c]) return dp[n][a][b][c];
        vector<int> col = {1,2,3};
        int ans = 0;
        for(auto a0 : col) {
            if(a == a0) continue;
            for(auto b0 : col) {
                if(b0 == b || b0 == a0) continue;
                for(auto c0 : col) {
                    if(c0 == c || b0 == c0) continue;
                    ans += dfs(n-1, a0, b0, c0);
                    ans %= 1000000007;
                }
            }
        }
        dp[n][a][b][c] = ans;
        return ans;
    }
};
