[1489.find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)  

Given a weighted undirected connected graph with `n` vertices numbered from `0` to `n-1`, and an array `edges` where `edges[i] = [fromi, toi, weighti]` represents a bidirectional and weighted edge between nodes `fromi` and `toi`. A minimum spanning tree (MST) is a subset of the edges of the graph that connects all vertices without cycles and with the minimum possible total edge weight.

Find _all the critical and pseudo-critical edges in the minimum spanning tree (MST) of the given graph_. An MST edge whose deletion from the graph would cause the MST weight to increase is called a _critical edge_. A _pseudo-critical edge_, on the other hand, is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/06/04/ex1.png)

  
**Input:** n = 5, edges = \[\[0,1,1\],\[1,2,1\],\[2,3,2\],\[0,3,2\],\[0,4,3\],\[3,4,3\],\[1,4,6\]\]  
**Output:** \[\[0,1\],\[2,3,4,5\]\]  
**Explanation:** The figure above describes the graph.  
The following figure shows all the possible MSTs:  
![](https://assets.leetcode.com/uploads/2020/06/04/msts.png)  
Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.  
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/06/04/ex2.png)

  
**Input:** n = 4, edges = \[\[0,1,1\],\[1,2,1\],\[2,3,1\],\[0,3,1\]\]  
**Output:** \[\[\],\[0,1,2,3\]\]  
**Explanation:** We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.  

**Constraints:**

*   `2 <= n <= 100`
*   `1 <= edges.length <= min(200, n * (n - 1) / 2)`
*   `edges[i].length == 3`
*   `0 <= fromi < toi < n`
*   `1 <= weighti <= 1000`
*   All pairs `(fromi, toi)` are distinct.  



**Solution:**  

```cpp
class Solution {
public:
    int p[105], m;
    int findp(int x){
        return p[x] == -1 ? x : p[x] = findp(p[x]);
    }
    
    int mst(vector<vector<int>>& e, int block = -1, int mustUse = -1){
        memset(p, -1, sizeof p);
        int best = 0;
        
        if(mustUse != -1){
            int a = findp(e[mustUse][0]), b = findp(e[mustUse][1]);
            p[b] = a;
            best += e[mustUse][2];
        }
        
        for(int i = 0; i < m; ++i){
            if(i == block) continue;
            int a = findp(e[i][0]), b = findp(e[i][1]);
            if(a != b){
                p[b] = a;
                best += e[i][2];
            }
        }
        
        return best;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        m = edges.size();
        for(int i = 0; i < m; ++i){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b){
            return a[2] < b[2];
        });
        
        int best = mst(edges);

        vector<int> retA, retB;
        for(int i = 0; i < m; ++i){
            if(best != mst(edges, i)){
                retA.push_back(edges[i][3]);
            }
            else if(best == mst(edges, -1, i)){
                retB.push_back(edges[i][3]);
            }
        }
        
        return {retA, retB};
    }
};
```
      