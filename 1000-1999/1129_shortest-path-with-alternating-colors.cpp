//Link: https://leetcode.com/problems/shortest-path-with-alternating-colors/ 
class Solution {
public:
    unordered_map<int, vector<vector<int> >  > m;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        for(auto &re : red_edges) {
            int b = re[0];
            int e = re[1];
            if(m[b].size() == 0)
                m[b].resize(2);
            m[b][0].push_back(e);
        }
        for(auto &re : blue_edges) {
            int b = re[0];
            int e = re[1];
            if(m[b].size() == 0)
                m[b].resize(2);
            m[b][1].push_back(e);
        }
        vector<int> ans = {0};
        for(int i = 1; i < n; ++i) {
            int a1 = bfs(i, 0);
            int a2 = bfs(i, 1);
            if(a1 == -1 || a2 == -1)
                ans.push_back(max(a1, a2));
            else
                ans.push_back(min(a1, a2));
            
        }
        return ans;
    }
    
    int bfs(int target, int color) {
        unordered_set<int> v;
        queue<pair<int, int> > q;
        q.push({0, color});
        v.insert(color);
        int path = 0;
        while(q.size() ){
            int size = q.size();
            while(size--) {
                auto point = q.front();
                q.pop();
                int node = point.first;
                int color = point.second == 0 ? 1 : 0;
                if(node == target)
                    return path;
                if(m[node].size() == 0)
                    continue;
                for(auto next: m[node][color]){
                    if(v.count((next<<16)+color))
                        continue;
                    v.insert((next<<16)+color);
                    q.push({next, color});
                }
            }
            ++path;
        }
        return -1;
    }
};