[1245.tree-diameter](https://leetcode.com/problems/tree-diameter/)  

Given an undirected tree, return its diameter: the number of **edges** in a longest path in that tree.

The tree is given as an array of `edges` where `edges[i] = [u, v]` is a bidirectional edge between nodes `u` and `v`.  Each node has labels in the set `{0, 1, ..., edges.length}`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/06/14/1397_example_1.PNG)

  
**Input:** edges = \[\[0,1\],\[0,2\]\]  
**Output:** 2  
**Explanation: **  
A longest path of the tree is the path 1 - 0 - 2.  

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/06/14/1397_example_2.PNG)

  
**Input:** edges = \[\[0,1\],\[1,2\],\[2,3\],\[1,4\],\[4,5\]\]  
**Output:** 4  
**Explanation: **  
A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.  

**Constraints:**

*   `0 <= edges.length < 10^4`
*   `edges[i][0] != edges[i][1]`
*   `0 <= edges[i][j] <= edges.length`
*   The given edges form an undirected tree.  



**Solution:**  

```cpp
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
```
      