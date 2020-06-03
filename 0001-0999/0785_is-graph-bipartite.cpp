//Link: https://leetcode.com/problems/is-graph-bipartite/ 
class Solution {
public:
    vector<int> m;
    bool isBipartite(vector<vector<int>>& graph) {        
        m.resize(graph.size());
        for(int i = 0; i < m.size(); ++i) 
            if(m[i] == 0 && !dfs(graph, i, 1))
                return false;
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, int i, int c) {
        if(m[i]) return m[i] == c;
        m[i] = c;
        for(auto &next : graph[i]) 
            if(!dfs(graph, next, -c))
                return false;
        return true;
    }
};