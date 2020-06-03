//Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/ 
class Solution {
public:
    map<int, vector<int> > g;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto &e : edges)
            g[e[0]].push_back(e[1]);
        auto res = dfs(0, hasApple);
        return res > 0 ? res - 2 : 0;
    }
    
    int dfs(int node, vector<bool>& hasApple) {
        if(node >= hasApple.size()) return 0;
        int ans = 0;
        for(auto &next : g[node])
            ans += dfs(next, hasApple);
        if(hasApple[node] || ans > 0)
            ans += 2;
        return ans;
    }
};