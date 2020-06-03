//Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/ 
class Solution {
public:
    unordered_map<int, unordered_set<int> > g;
    unordered_map<int, unordered_set<int> > gd;
    vector<int> v;
    int ans = 0;
    int minReorder(int n, vector<vector<int>>& connections) {
        v.resize(n);
        for(auto &c : connections) {
            g[c[0]].insert(c[1]);
            g[c[1]].insert(c[0]);
            gd[c[0]].insert(c[1]);
        }
        dfs(0, 0);
        return ans;
    }
    
    void dfs(int prev, int node) {
        if(v[node]) return;
        if(node != prev) {
            if(gd[node].count(prev) == 0)
                ++ans;
        }
        v[node] = 1;
        for(auto next : g[node]) {
            dfs(node, next);
        }
    }
};