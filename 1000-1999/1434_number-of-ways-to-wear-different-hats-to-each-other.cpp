//Link: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/ 
class Solution {
public:
    vector<int> hat[41];
    map<int, map<int, int> > dp;
    int all = 0;
    int numberWays(vector<vector<int>>& hats) {
        for(int i = 0; i < hats.size(); ++i) {
            for(auto h : hats[i])
                hat[h].push_back(i);
        }
        all = (1 << (hats.size()))-1;
        return dfs(0, 0);
    }
    
    int dfs(int mask, int idx) {
        if(idx > 40) return mask == all;
        if(dp[idx].count(mask)) return dp[idx][mask];
        int ans = dfs( mask, idx + 1);
        for(auto n : hat[idx]) {
            if(mask & (1 << n)) continue;
            ans += dfs(mask | ( 1 << n), idx + 1);
            ans %= 1000000007;
        }
        dp[idx][mask] = ans;
        return ans;
    }
};