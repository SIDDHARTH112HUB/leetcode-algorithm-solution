//Link: https://leetcode.com/problems/tree-diameter/ 
class Solution {
public:
    unordered_map<int, vector<int> > g;
    unordered_set<int> v;
    int ans = 0;
    int treeDiameter(vector<vector<int>>& edges) {
        for(auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(edges[0][0]);
        return ans;
    }
    
    int dfs(int node) {
        if(v.count(node)) return 0;
        v.insert(node);
        priority_queue<int> pq;
        pq.push(0);
        pq.push(0);
        for(auto next : g[node]) {
            if(v.count(next)) continue;
            int res = 1 + dfs(next);
            pq.push(-res);
            if(pq.size() > 2) pq.pop();
        }
        int mx = -pq.top();pq.pop();
        int mx2 = -pq.top();
        ans = max(ans, mx + mx2);
        return max(mx2, mx);
    }
};