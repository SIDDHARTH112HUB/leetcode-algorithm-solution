[323.number-of-connected-components-in-an-undirected-graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)  

Given `n` nodes labeled from `0` to `n - 1` and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

**Example 1:**

  
**Input:** `n = 5` and `edges = [[0, 1], [1, 2], [3, 4]]`
  

  
     0          3
  
     |          |
  
     1 --- 2    4 
  

  
**Output:** 2
  

**Example 2:**

  
**Input:** `n = 5` and `edges = [[0, 1], [1, 2], [2, 3], [3, 4]]`
  

  
     0           4
  
     |           |
  
     1 --- 2 --- 3
  

  
**Output:** 1
  

**Note:**  
You can assume that no duplicate edges will appear in `edges`. Since all edges are undirected, `[0, 1]` is the same as `[1, 0]` and thus will not appear together in `edges`.  



**Solution:**  

```cpp
class Solution {
public:
    map<int, int> m;
    int group = 0;
    int find(int x) {
        if(m.count(x)) return m[x] == x ? x : (m[x] = find(m[x]));
        ++group;
        return m[x] = x;
    }
    void combine(int a, int b) {
        if((a = find(a)) != (b = find(b))) {
            --group;
            m[a] = b;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; ++i) find(i);
        for(auto &e : edges) 
            combine(e[0], e[1]);
        return group;
    }
};
```
      