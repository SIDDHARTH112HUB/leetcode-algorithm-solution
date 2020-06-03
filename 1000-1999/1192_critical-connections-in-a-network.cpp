//Link: https://leetcode.com/problems/critical-connections-in-a-network/ 
#define MAX_N 100005
int dfn[MAX_N];
int low[MAX_N];
int vis[MAX_N];
int instack[MAX_N];
struct Tarjan{
    
    unordered_map<int, unordered_set<int> > graph;
    set<vector<int>> ans;
    int idx = 0;
    int n = 0;
    Tarjan(int n ) {
        this->n = n;
        memset(dfn, 0, sizeof(int)*n);
        memset(low, 0, sizeof(int)*n);
        memset(vis, 0, sizeof(int)*n);
        memset(instack, 0, sizeof(int)*n);
    }
    void add(int a, int b) {
        graph[a].insert(b);
        graph[b].insert(a);
    }
    stack<int> stk;
    void solve() {
        for(int i = 0; i < n; ++i) {
            if(!vis[i])
                dfs(i, -1);
        }
    }
    void dfs(int u, int p) {
        if(vis[u]) return;
        vis[u] = true;
        dfn[u] = low[u] = ++idx;
        instack[u] = true;
        for(auto v : graph[u]) {
            if(v == p) continue;
            if(!vis[v]) {
                dfs(v, u);
                low[u] = min(low[v], low[u]);
                if(low[v] > dfn[u])
                    ans.insert({min(u,v), max(u,v)});
            }else if(instack[v]){
                low[u] = min(low[u], dfn[v]);
            }
        }
        instack[u] = false;
    }
};
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        Tarjan t(n);
        for(auto &c : connections) {
            t.add(c[0], c[1]);
        }
        t.solve();
        return vector<vector<int> >(t.ans.begin(), t.ans.end());
    }
};