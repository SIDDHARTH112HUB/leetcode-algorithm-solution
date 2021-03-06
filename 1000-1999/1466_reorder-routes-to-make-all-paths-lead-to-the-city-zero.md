[1466.reorder-routes-to-make-all-paths-lead-to-the-city-zero](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)  

There are `n` cities numbered from `0` to `n-1` and `n-1` roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by `connections` where `connections[i] = [a, b]` represents a road from city `a` to `b`.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the **minimum** number of edges changed.

It's **guaranteed** that each city can reach the city 0 after reorder.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/05/13/sample_1_1819.png)**

  
**Input:** n = 6, connections = \[\[0,1\],\[1,3\],\[2,3\],\[4,0\],\[4,5\]\]  
**Output:** 3  
**Explanation:** Change the direction of edges show in red such that each node can reach the node 0 (capital).

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/05/13/sample_2_1819.png)**

  
**Input:** n = 5, connections = \[\[1,0\],\[1,2\],\[3,2\],\[3,4\]\]  
**Output:** 2  
**Explanation:** Change the direction of edges show in red such that each node can reach the node 0 (capital).

**Example 3:**

  
**Input:** n = 3, connections = \[\[1,0\],\[2,0\]\]  
**Output:** 0  

**Constraints:**

*   `2 <= n <= 5 * 10^4`
*   `connections.length == n-1`
*   `connections[i].length == 2`
*   `0 <= connections[i][0], connections[i][1] <= n-1`
*   `connections[i][0] != connections[i][1]`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_set<int> > g;
    unordered_map<int, unordered_set<int> > gd;
    vector<int> v;
    int ans = 0;
    int minReorder(int n, vector<vector<int>>& connections) {
        v.resize(n);
        for(auto &c : connections) {
            g[c[0]].insert(c[1]);
            g[c[1]].insert(c[0]);
            gd[c[0]].insert(c[1]);
        }
        dfs(0, 0);
        return ans;
    }
    
    void dfs(int prev, int node) {
        if(v[node]) return;
        if(node != prev) {
            if(gd[node].count(prev) == 0)
                ++ans;
        }
        v[node] = 1;
        for(auto next : g[node]) {
            dfs(node, next);
        }
    }
};
```
      