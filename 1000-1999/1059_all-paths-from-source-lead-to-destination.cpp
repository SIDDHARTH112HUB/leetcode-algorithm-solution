//Link: https://leetcode.com/problems/all-paths-from-source-lead-to-destination/ 
class Solution {
public:
    map<int, set<int> > g;
    set<int> v, vd;
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto &e : edges) {
            g[e[0]].insert(e[1]);
            if(e[0] == destination) return false;
        }
        return dfs(source, destination);
    }
    
    bool dfs(int node, int t) {
        if(v.count(node)) {
            return false;
        }
        if(node == t) return true;
        v.insert(node);
        bool res = g[node].size() > 0;
        for(auto next : g[node]) {
            res =  res && dfs(next, t);
            if(!res) break;
        }
        if(res) vd.insert(node);
        v.erase(node);
        return res;
    }
};