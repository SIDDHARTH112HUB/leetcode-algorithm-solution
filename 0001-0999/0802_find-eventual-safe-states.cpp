//Link: https://leetcode.com/problems/find-eventual-safe-states/ 
#define CIRCLE 2
#define TERMINAL 1
class Solution {
public:
    vector<int> v;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        v.resize(n);
        vector<int> ans;
        for(int i = 0; i < n; ++i)
            if(dfs(graph, i) == TERMINAL)
                ans.push_back(i);
        return ans;
    }
    int dfs(vector<vector<int>>& g, int n) {
        if(v[n]) return v[n];
        v[n] = CIRCLE;
        for(auto next : g[n])
            if(dfs(g, next) == CIRCLE)
                return CIRCLE;
        return v[n] = TERMINAL;
    }
};