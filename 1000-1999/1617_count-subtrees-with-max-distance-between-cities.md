[1617.count-subtrees-with-max-distance-between-cities](https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/)  

There are `n` cities numbered from `1` to `n`. You are given an array `edges` of size `n-1`, where `edges[i] = [ui, vi]` represents a bidirectional edge between cities `ui` and `vi`. There exists a unique path between each pair of cities. In other words, the cities form a **tree**.

A **subtree** is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.

For each `d` from `1` to `n-1`, find the number of subtrees in which the **maximum distance** between any two cities in the subtree is equal to `d`.

Return _an array of size_ `n-1` _where the_ `dth` _element **(1-indexed)** is the number of subtrees in which the **maximum distance** between any two cities is equal to_ `d`.

**Notice** that the **distance** between the two cities is the number of edges in the path between them.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/09/21/p1.png)**

  
**Input:** n = 4, edges = \[\[1,2\],\[2,3\],\[2,4\]\]
  
**Output:** \[3,4,0\]
  
**Explanation:** The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
  
The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
  
No subtree has two nodes where the max distance between them is 3.
  

**Example 2:**

  
**Input:** n = 2, edges = \[\[1,2\]\]
  
**Output:** \[1\]
  

**Example 3:**

  
**Input:** n = 3, edges = \[\[1,2\],\[2,3\]\]
  
**Output:** \[2,1\]
  

**Constraints:**

*   `2 <= n <= 15`
*   `edges.length == n-1`
*   `edges[i].length == 2`
*   `1 <= ui, vi <= n`
*   All pairs `(ui, vi)` are distinct.  



**Solution:**  

```cpp
/*here is the idea:
1. iterate all the possible subtree from 1 to (1 << n - 1), the positions of `1` bits are the tree node ID.
2. use dfs to calcuate the maximum distance for the subtree.
3. verfiy if the subtree is valid. once we visited a node then we clear the specific bit in the subtree, after finishing dfs, if subtree == 0, that means it is a valid subtree.
4. update ans by the maximum distance.
*/

class Solution {
public:
    unordered_set<int> g[16];
    int dfs(int u, int p, int &subtree, int &mx) {
        subtree = subtree ^ (1 << (u - 1));  //clear visited Node bit.
        int a = 0, b = 0;
        for(auto v : g[u]) {
            if(v == p) continue;
            if((subtree & (1 << (v - 1))) == 0) continue; //the next node is not included in the subtree, ignore this node.
            int res = dfs(v, u, subtree, mx) + 1;
            if(res > a) {
                b = a; a = res;
            } else if(res > b) {
                b = res;
            }
        }
        mx = max(mx, a + b);    //get the maximum distance in the subtree.
        return a;  //return the longest path from current node.
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n - 1);
        for(auto &e : edges) {     //build graph.
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        int size = 1 << n;
        for(int i = 1; i < size; ++i) {
            if(((i - 1) & i) == 0) continue;  //we don't need to calculate the subtree which have one node only.
            int subtree = i;
            int u = 0;
            int mx = 0;
            for(int j = 0; j < n; ++j) {  // to get the start node.
                if((1 <<j) & i) {
                    u = j + 1;
                    break;
                }
            }
            int res = dfs(u, -1, subtree, mx);
            if(subtree == 0) {
                ++ans[mx - 1];
            }
        }
        return ans;
    }
};

```
      