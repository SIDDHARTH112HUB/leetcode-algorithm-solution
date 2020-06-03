//Link: https://leetcode.com/problems/delete-tree-nodes/ 
class Solution {
public:
    map<int, map<int, int> > t;
    int ans = 0;
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        for(int i = 0; i < parent.size(); ++i) {
            int p = parent[i];
            t[p][i] = value[i];
        }
        dfs(-1, value);
        h(-1);
        return ans;
    }
    
    int dfs(int node, vector<int>& value) {
        int sum = 0;
        if(node != -1)
            sum += value[node];
        vector<int> er;
        for(auto it : t[node]) {
            int next = it.first;
            int val = dfs(next, value);
            if(val == 0) {
                t[next] = {};
                er.push_back(next);
            }
            sum += val;
        }
        for(auto next : er) 
            t[node].erase(next);
        return sum;
    }
    
    void h(int node) {
        if(node != -1) ++ans;
        for(auto it : t[node]) {
            h(it.first);
        }
    }
};