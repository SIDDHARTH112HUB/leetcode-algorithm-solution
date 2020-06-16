[1192.critical-connections-in-a-network](https://leetcode.com/problems/critical-connections-in-a-network/)  

There are `n` servers numbered from `0` to `n-1` connected by undirected server-to-server `connections` forming a network where `connections[i] = [a, b]` represents a connection between servers `a` and `b`. Any server can reach any other server directly or indirectly through the network.

A _critical connection_ is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/09/03/1537_ex1_2.png)**

  
**Input:** n = 4, connections = \[\[0,1\],\[1,2\],\[2,0\],\[1,3\]\]  
**Output:** \[\[1,3\]\]  
**Explanation:** \[\[3,1\]\] is also accepted.  

**Constraints:**

*   `1 <= n <= 10^5`
*   `n-1 <= connections.length <= 10^5`
*   `connections[i][0] != connections[i][1]`
*   There are no repeated connections.  



**Solution:**  

```cpp
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
```
      