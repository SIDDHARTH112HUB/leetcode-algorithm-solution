[1273.delete-tree-nodes](https://leetcode.com/problems/delete-tree-nodes/)  

A tree rooted at node 0 is given as follows:

*   The number of nodes is `nodes`;
*   The value of the `i`\-th node is `value[i]`;
*   The parent of the `i`\-th node is `parent[i]`.

Remove every subtree whose sum of values of nodes is zero.

After doing so, return the number of nodes remaining in the tree.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/07/02/1421_sample_1.PNG)

  
**Input:** nodes = 7, parent = \[-1,0,0,1,2,2,2\], value = \[1,-2,4,0,-2,-1,-1\]  
**Output:** 2  

**Constraints:**

*   `1 <= nodes <= 10^4`
*   `-10^5 <= value[i] <= 10^5`
*   `parent.length == nodes`
*   `parent[0] == -1` which indicates that `0` is the root.  



**Solution:**  

```cpp
class Solution {
public:
    map<int, map<int, int> > t;
    int ans = 0;
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        for(int i = 0; i < parent.size(); ++i) {
            int p = parent[i];
            t[p][i] = value[i];
        }
        dfs(-1, value);
        h(-1);
        return ans;
    }
    
    int dfs(int node, vector<int>& value) {
        int sum = 0;
        if(node != -1)
            sum += value[node];
        vector<int> er;
        for(auto it : t[node]) {
            int next = it.first;
            int val = dfs(next, value);
            if(val == 0) {
                t[next] = {};
                er.push_back(next);
            }
            sum += val;
        }
        for(auto next : er) 
            t[node].erase(next);
        return sum;
    }
    
    void h(int node) {
        if(node != -1) ++ans;
        for(auto it : t[node]) {
            h(it.first);
        }
    }
};
```
      