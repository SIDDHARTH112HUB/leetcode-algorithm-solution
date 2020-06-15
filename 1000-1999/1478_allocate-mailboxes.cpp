//Link: https://leetcode.com/problems/allocate-mailboxes/ 
#define MAXN 10020
#define MAXM 2010000
class Solution {
public:
    int dp[101][101];
    int cost[101][101];
    int minDistance(vector<int>& houses, int mailCnt) {
        sort(houses.begin(), houses.end());
        memset(dp, -1, sizeof(dp));
        memset(cost, 0, sizeof(cost));
        int n = houses.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = i; k <= j; ++k) {
                    cost[i][j] += abs(houses[(i + j)/ 2] - houses[k]);
                }
            }
        }
        return dfs(houses, 0, houses.size(), mailCnt);
    }
    
    int dfs(vector<int> &h, int i, int n, int mailCnt) {
        if(mailCnt == 0 && i == n) return 0;
        if(mailCnt == 0 || i == n) return 1e+9;
        if(dp[i][mailCnt] >= 0) return dp[i][mailCnt];
        int res = 1e+9;
        for(int k = i; k < n; ++k) {
            int mid = (i + k) / 2;
            res = min(res, cost[i][k] + dfs(h, k + 1, n, mailCnt - 1));
        }
        return dp[i][mailCnt] = res;
    }
};