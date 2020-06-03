//Link: https://leetcode.com/problems/maximum-vacation-days/ 
class Solution {
public:
    int dp[100][100] = {};
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        memset(dp, -1, sizeof(dp));
        int res = dfs(flights, days, 0, 0);
        return res;
    }
    
    int dfs(vector<vector<int>>& flights, vector<vector<int>>& days, int n, int k) {
        if(n >= flights.size()) return 0;
        if(k >= days[0].size()) return 0;
        if(dp[n][k] >= 0) return dp[n][k];
        int res = 0;
        for(int i = 0; i < flights[n].size(); ++i) {
            int f = flights[n][i];
            if(f || n == i)
                res = max(res, days[i][k] + dfs(flights, days, i, k + 1));
        }
        return dp[n][k] = res;
    }
};