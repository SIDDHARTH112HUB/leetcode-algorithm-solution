//Link: https://leetcode.com/problems/sum-of-distances-in-tree/ 
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> count(N, 1), ans(N);
        cout<<count[0];
        vector<set<int>> nodes(N);
        
        for( auto &edge: edges){
            nodes[edge[0]].insert(edge[1]);
            nodes[edge[1]].insert(edge[0]);
        }
        
        dfs(0, -1, nodes, count, ans);
        dfs2(0, -1,nodes, count, ans, N);
        return ans;
    }
    void dfs(int node, int parent, vector<set<int>>& nodes,vector<int>& count, vector<int>& ans){
        for( int sub: nodes[node]){
            if( sub == parent )
                continue;
            dfs(sub, node, nodes, count, ans);
            count[node] += count[sub];
            ans[node] += (ans[sub] + count[sub]);
        }
    }
    void dfs2(int node, int parent, vector<set<int>>& nodes,vector<int>& count, vector<int>& ans, int N){
        for( int sub:nodes[node]){
            if( sub == parent )
                continue;
            ans[sub] = ans[node] - count[sub] + N - count[sub];
            dfs2(sub, node, nodes, count, ans, N);
        }
    }
};