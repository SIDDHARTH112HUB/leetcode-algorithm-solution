[1042.flower-planting-with-no-adjacent](https://leetcode.com/problems/flower-planting-with-no-adjacent/)  

You have `N` gardens, labelled `1` to `N`.  In each garden, you want to plant one of 4 types of flowers.

`paths[i] = [x, y]` describes the existence of a bidirectional path from garden `x` to garden `y`.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return **any** such a choice as an array `answer`, where `answer[i]` is the type of flower planted in the `(i+1)`\-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

**Example 1:**

**Input:** N = 3, paths = \[\[1,2\],\[2,3\],\[3,1\]\]
**Output:** \[1,2,3\]

**Example 2:**

**Input:** N = 4, paths = \[\[1,2\],\[3,4\]\]
**Output:** \[1,2,1,2\]

**Example 3:**

**Input:** N = 4, paths = \[\[1,2\],\[2,3\],\[3,4\],\[4,1\],\[1,3\],\[2,4\]\]
**Output:** \[1,2,3,4\]

**Note:**

*   `1 <= N <= 10000`
*   `0 <= paths.size <= 20000`
*   No garden has 4 or more paths coming into or leaving it.
*   It is guaranteed an answer exists.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_set<int> > graph;
    vector<int> ans;
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        ans.resize(N);
        for(auto &path: paths) {
            int x = path[0];
            int y = path[1];
            graph[x].insert(y);
            graph[y].insert(x);
        }
        for(int i = 1; i <= N; i++)
            dfs(i);
        return ans;
    }
    
    void dfs(int garden) {
        if(ans[garden-1] > 0)
            return;
        
        for( int f = 1; f <=4; f++) {
            bool isFind = true;
            for(int g : graph[garden]) {
                if ( ans[g-1] == f) {
                    isFind = false;
                    break;
                }
            }
            if(isFind){
                ans[garden-1] = f;
                break;
            }
        }
        for(auto g : graph[garden]) {
            dfs(g);
        }
    }
};
```
      