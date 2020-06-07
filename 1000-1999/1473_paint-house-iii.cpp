//Link: https://leetcode.com/problems/paint-house-iii/ 
class Solution {
public:
    int dp[101][23][101];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int res = dfs(houses, cost, 0, n + 1, target);
        return res >= 10000000 ? -1 : res;
    }
    
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int prev, int target) {
        if(i >= houses.size())
            return target != 0 ? 10000000 : 0;
        if(target < 0) return 10000000;
        if(dp[i][prev][target] >= 0) return dp[i][prev][target];
        int res = INT_MAX;
        if(houses[i] == 0) {
            for(int j = 0; j < cost[i].size(); ++j) 
                res = min(res, cost[i][j] + dfs(houses, cost, i + 1, j+1, target - (j+1 != prev)));
        }else
            res = min(res, dfs(houses, cost, i + 1, houses[i], target - (houses[i] != prev)));
        return dp[i][prev][target] = res;
    }
};