//Link: https://leetcode.com/problems/possible-bipartition/ 
class Solution {
public:
    vector<int> v;
    map<int, set< int> > g;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        v.resize(N + 1);
        for(auto &d : dislikes) {
            g[d[0]].insert(d[1]);
            g[d[1]].insert(d[0]);
        }
        for(int i = 1; i <= N; ++i) {
            
            if(!dfs(i, v[i] ? v[i] : 1)) return false;
        }
        return true;
    }
    
    bool dfs(int node, int col) {
        if(v[node]) {
            return v[node] == col;
        }
        v[node] = col;
        for(auto next : g[node]) {
            if(!dfs(next, -col))return false;
        }
        return true;
    }
};