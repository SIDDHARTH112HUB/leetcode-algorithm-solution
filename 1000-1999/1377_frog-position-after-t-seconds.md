[1377.frog-position-after-t-seconds](https://leetcode.com/problems/frog-position-after-t-seconds/)  

Given an undirected tree consisting of `n` vertices numbered from 1 to `n`. A frog starts jumping from the **vertex 1**. In one second, the frog jumps from its current vertex to another **unvisited** vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices it jumps randomly to one of them with the same probability, otherwise, when the frog can not jump to any unvisited vertex it jumps forever on the same vertex. 

The edges of the undirected tree are given in the array `edges`, where `edges[i] = [fromi, toi]` means that exists an edge connecting directly the vertices `fromi` and `toi`.

_Return the probability that after `t` seconds the frog is on the vertex `target`._

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/02/20/frog_2.png)

  
**Input:** n = 7, edges = \[\[1,2\],\[1,3\],\[1,7\],\[2,4\],\[2,6\],\[3,5\]\], t = 2, target = 4
  
**Output:** 0.16666666666666666 
  
**Explanation:** The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after **second 1** and then jumping with 1/2 probability to vertex 4 after **second 2**. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 \* 1/2 = 1/6 = 0.16666666666666666. 
  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/02/20/frog_3.png)**

  
**Input:** n = 7, edges = \[\[1,2\],\[1,3\],\[1,7\],\[2,4\],\[2,6\],\[3,5\]\], t = 1, target = 7
  
**Output:** 0.3333333333333333
  
**Explanation:** The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after **second 1**. 
  

**Example 3:**

  
**Input:** n = 7, edges = \[\[1,2\],\[1,3\],\[1,7\],\[2,4\],\[2,6\],\[3,5\]\], t = 20, target = 6
  
**Output:** 0.16666666666666666
  

**Constraints:**

*   `1 <= n <= 100`
*   `edges.length == n-1`
*   `edges[i].length == 2`
*   `1 <= edges[i][0], edges[i][1] <= n`
*   `1 <= t <= 50`
*   `1 <= target <= n`
*   Answers within `10^-5` of the actual value will be accepted as correct.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> path;
    map<int, vector<int> > m;
    double ans = 1;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        for(auto &e : edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        cout<<"begin"<<endl;
        int depth = dfs(1, -1, target);
        cout<<depth<<" "<<path.size()<<endl;
        if(depth > t + 1) return 0;
        if(depth < t + 1 ) {
            if( m[target].size() - (t != 1) != 0)
                return 0;
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        
        for(auto n :  path) cout<<n<<" ";
        cout<<endl;
        
        dfs2(0, -1, t+1, target);
        return ans;
    }
    
    void dfs2(int idx, int p, int t, int target) {
        if(idx >= path.size()) {
            if(t == 0) return;
            if(m[path.back()].size() > (target != 1))
                ans = 0.0;
            return;
        }
        idx = min(idx, (int)path.size() - 1);
        if(t == 0) {
            if(path[idx] != target)
                ans = 0;
            return;
        }
        int len = (int)m[path[idx]].size() - (p != -1);
        if(len <= 0) return;
        //cout<<ans<<" "<<len<<endl;
        ans *= 1.0 / len;
        dfs2(idx + 1, 0, t - 1, target);
    }
    int dfs(int node, int p, int target) {
        if(node == target) return true;
        for(auto &next : m[node]) {
            if(next == p) continue;
            int res = dfs(next, node, target);
            if(res) {
                path.push_back(next);
                return res + 1;
            }
        }
        return false;
    }
};
```
      