[797.all-paths-from-source-to-target](https://leetcode.com/problems/all-paths-from-source-to-target/)  

Given a directed, acyclic graph of `N` nodes.  Find all possible paths from node `0` to node `N-1`, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph\[i\] is a list of all nodes j for which the edge (i, j) exists.

**Example:**
**Input:** \[\[1,2\], \[3\], \[3\], \[\]\] 
**Output:** \[\[0,1,3\],\[0,2,3\]\] 
**Explanation:** The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

**Note:**

*   The number of nodes in the graph will be in the range `[2, 15]`.
*   You can print different paths in any order, but you should keep the order of nodes inside one path.  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int des = graph.size()-1;
        vector< vector<int> > path,ans;
        for(auto n: graph[0] ){
            vector<int> p;
            p.push_back(0);
            p.push_back(n);
            if( n == des )
                ans.push_back(p);
            else
                path.push_back(p);
        }
        while(path.size()>0){
            auto back = path.back();
            path.pop_back();
            for( auto n: graph[back.back()]) {
                printf("back.back():%d , n:%d\n",back.back(), n );
                back.push_back(n);
                if(n == des){
                    ans.push_back(back);
                }else{
                    path.push_back(back);
                }
                back.pop_back();
            }
        }
        return ans;
    }
};
```
      