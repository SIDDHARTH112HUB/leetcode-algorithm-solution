[1443.minimum-time-to-collect-all-apples-in-a-tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)  

Given an undirected tree consisting of `n` vertices numbered from 0 to `n-1`, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. _Return the minimum time in seconds you have to spend in order to collect all apples in the tree starting at **vertex 0** and coming back to this vertex._

The edges of the undirected tree are given in the array `edges`, where `edges[i] = [fromi, toi]` means that exists an edge connecting the vertices `fromi` and `toi`. Additionally, there is a boolean array `hasApple`, where `hasApple[i] = true` means that vertex `i` has an apple, otherwise, it does not have any apple.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_1.png)**

  
**Input:** n = 7, edges = \[\[0,1\],\[0,2\],\[1,4\],\[1,5\],\[2,3\],\[2,6\]\], hasApple = \[false,false,true,false,true,true,false\]  
**Output:** 8   
**Explanation:** The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.    

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_2.png)**

  
**Input:** n = 7, edges = \[\[0,1\],\[0,2\],\[1,4\],\[1,5\],\[2,3\],\[2,6\]\], hasApple = \[false,false,true,false,false,true,false\]  
**Output:** 6  
**Explanation:** The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.    

**Example 3:**

  
**Input:** n = 7, edges = \[\[0,1\],\[0,2\],\[1,4\],\[1,5\],\[2,3\],\[2,6\]\], hasApple = \[false,false,false,false,false,false,false\]  
**Output:** 0  

**Constraints:**

*   `1 <= n <= 10^5`
*   `edges.length == n-1`
*   `edges[i].length == 2`
*   `0 <= fromi, toi <= n-1`
*   `fromi < toi`
*   `hasApple.length == n`  



**Solution:**  

```cpp
class Solution {
public:
    map<int, vector<int> > g;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto &e : edges)
            g[e[0]].push_back(e[1]);
        auto res = dfs(0, hasApple);
        return res > 0 ? res - 2 : 0;
    }
    
    int dfs(int node, vector<bool>& hasApple) {
        if(node >= hasApple.size()) return 0;
        int ans = 0;
        for(auto &next : g[node])
            ans += dfs(next, hasApple);
        if(hasApple[node] || ans > 0)
            ans += 2;
        return ans;
    }
};
```
      