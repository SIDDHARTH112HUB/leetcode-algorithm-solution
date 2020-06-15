[834.sum-of-distances-in-tree](https://leetcode.com/problems/sum-of-distances-in-tree/)  

An undirected, connected tree with `N` nodes labelled `0...N-1` and `N-1` `edges` are given.

The `i`th edge connects nodes `edges[i][0]` and `edges[i][1]` together.

Return a list `ans`, where `ans[i]` is the sum of the distances between node `i` and all other nodes.

**Example 1:**

**Input:** N = 6, edges = \[\[0,1\],\[0,2\],\[2,3\],\[2,4\],\[2,5\]\]
**Output:** \[8,12,6,10,10,10\]
**Explanation:** 
Here is a diagram of the given tree:
  0
 / \\
1   2
   /|\\
  3 4 5
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer\[0\] = 8, and so on.

Note: `1 <= N <= 10000`  



**Solution:**  

```cpp
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
```
      