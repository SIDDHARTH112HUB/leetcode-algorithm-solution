[1129.shortest-path-with-alternating-colors](https://leetcode.com/problems/shortest-path-with-alternating-colors/)  

Consider a directed graph, with nodes labelled `0, 1, ..., n-1`.  In this graph, each edge is either red or blue, and there could be self-edges or parallel edges.

Each `[i, j]` in `red_edges` denotes a red directed edge from node `i` to node `j`.  Similarly, each `[i, j]` in `blue_edges` denotes a blue directed edge from node `i` to node `j`.

Return an array `answer` of length `n`, where each `answer[X]` is the length of the shortest path from node `0` to node `X` such that the edge colors alternate along the path (or `-1` if such a path doesn't exist).

**Example 1:**

**Input:** n = 3, red\_edges = \[\[0,1\],\[1,2\]\], blue\_edges = \[\]
  
**Output:** \[0,1,-1\]
  

**Example 2:**

**Input:** n = 3, red\_edges = \[\[0,1\]\], blue\_edges = \[\[2,1\]\]
  
**Output:** \[0,1,-1\]
  

**Example 3:**

**Input:** n = 3, red\_edges = \[\[1,0\]\], blue\_edges = \[\[2,1\]\]
  
**Output:** \[0,-1,-1\]
  

**Example 4:**

**Input:** n = 3, red\_edges = \[\[0,1\]\], blue\_edges = \[\[1,2\]\]
  
**Output:** \[0,1,2\]
  

**Example 5:**

**Input:** n = 3, red\_edges = \[\[0,1\],\[0,2\]\], blue\_edges = \[\[1,0\]\]
  
**Output:** \[0,1,1\]
  

**Constraints:**

*   `1 <= n <= 100`
*   `red_edges.length <= 400`
*   `blue_edges.length <= 400`
*   `red_edges[i].length == blue_edges[i].length == 2`
*   `0 <= red_edges[i][j], blue_edges[i][j] < n`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, vector<vector<int> >  > m;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        for(auto &re : red_edges) {
            int b = re[0];
            int e = re[1];
            if(m[b].size() == 0)
                m[b].resize(2);
            m[b][0].push_back(e);
        }
        for(auto &re : blue_edges) {
            int b = re[0];
            int e = re[1];
            if(m[b].size() == 0)
                m[b].resize(2);
            m[b][1].push_back(e);
        }
        vector<int> ans = {0};
        for(int i = 1; i < n; ++i) {
            int a1 = bfs(i, 0);
            int a2 = bfs(i, 1);
            if(a1 == -1 || a2 == -1)
                ans.push_back(max(a1, a2));
            else
                ans.push_back(min(a1, a2));
            
        }
        return ans;
    }
    
    int bfs(int target, int color) {
        unordered_set<int> v;
        queue<pair<int, int> > q;
        q.push({0, color});
        v.insert(color);
        int path = 0;
        while(q.size() ){
            int size = q.size();
            while(size--) {
                auto point = q.front();
                q.pop();
                int node = point.first;
                int color = point.second == 0 ? 1 : 0;
                if(node == target)
                    return path;
                if(m[node].size() == 0)
                    continue;
                for(auto next: m[node][color]){
                    if(v.count((next<<16)+color))
                        continue;
                    v.insert((next<<16)+color);
                    q.push({next, color});
                }
            }
            ++path;
        }
        return -1;
    }
};
```
      