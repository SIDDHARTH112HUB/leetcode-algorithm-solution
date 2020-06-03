//Link: https://leetcode.com/problems/campus-bikes-ii/ 
class Solution {
public:
    unordered_map<int, int> dp;
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        return dfs(workers, bikes, 0, 0);
    }
    int dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes, int mask, int w) {
        if(w >= workers.size()) return 0;
        if(dp.count(mask)) return dp[mask];
        int res = INT_MAX;
        for(int i = 0; i < bikes.size(); ++i) {
            if(mask & (1 << i )) continue;
            int dis = abs(workers[w][0] - bikes[i][0]) + abs(workers[w][1] - bikes[i][1]);
            res = min(res, dfs(workers, bikes, mask  | (1 << i), w + 1  ) + dis);
            
        }
        return dp[mask] = res;
    }
};