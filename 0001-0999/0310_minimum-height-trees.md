[310.minimum-height-trees](https://leetcode.com/problems/minimum-height-trees/)  

For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

**Format**  
The graph contains `n` nodes which are labeled from `0` to `n - 1`. You will be given the number `n` and a list of undirected `edges` (each edge is a pair of labels).

You can assume that no duplicate edges will appear in `edges`. Since all edges are undirected, `[0, 1]` is the same as `[1, 0]` and thus will not appear together in `edges`.

**Example 1 :**

  
**Input:** `n = 4`, `edges = [[1, 0], [1, 2], [1, 3]]`
  

  
        0
  
        |
  
        1
  
       / \\
  
      2   3 
  

  
**Output:** `[1]`
  

**Example 2 :**

  
**Input:** `n = 6`, `edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]`
  

  
     0  1  2
  
      \\ | /
  
        3
  
        |
  
        4
  
        |
  
        5 
  

  
**Output:** `[3, 4]`

**Note**:

*   According to the [definition of tree on Wikipedia](https://en.wikipedia.org/wiki/Tree_(graph_theory)): “a tree is an undirected graph in which any two vertices are connected by _exactly_ one path. In other words, any connected graph without simple cycles is a tree.”
*   The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > g;
    unordered_set<int> v;
    vector<int> ans;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(auto &e :edges) {
            g[e[0]][e[1]] = 1;
            g[e[1]][e[0]] = 1;
        }
        dfs(0);
        /*for(auto it : g) {
            for(auto it2 : it.second) {
                cout<<it.first<<"--->"<<it2.first<<" d:"<<it2.second<<endl;
            }
        }*/
        helper(0);
        return ans;
    }
    
    int helper(int i) {
        int mx = 0, mxp = -1;
        for(auto it : g[i]) {
            if(it.second > mx) {
                mx = it.second;
                mxp = it.first;
            }
        }
        int sx = 0, sxp = -1;
        for(auto it: g[i]) {
            if(it.second > sx && it.first != mxp) {
                sx = it.second;
                sxp = it.first;
            }
        }
        if(mx == sx) {
            ans = {i};
            return 0;
        }
        if(mx - sx == 1) {
            ans = {i, mxp};
            return 0;
        }
        g[mxp][i] = g[i][mxp] = sx + 1;
        return helper(mxp);
    }
    
    int dfs(int i) {
        if(v.count(i)) return 0;
        v.insert(i);
        int mx = 0;
        for(auto &it : g[i]) {
            if(v.count(it.first)) continue;
            int h = 1 + dfs(it.first);
            g[i][it.first] = h;
            g[it.first][i] = h;
            mx = max(mx, h);
        }
        return mx;
    }
};
```
      