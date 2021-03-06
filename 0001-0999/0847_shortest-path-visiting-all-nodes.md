[847.shortest-path-visiting-all-nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)  

An undirected, connected graph of N nodes (labeled `0, 1, 2, ..., N-1`) is given as `graph`.

`graph.length = N`, and `j != i` is in the list `graph[i]` exactly once, if and only if nodes `i` and `j` are connected.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

**Example 1:**

  
**Input:** \[\[1,2,3\],\[0\],\[0\],\[0\]\]
  
**Output:** 4
  
**Explanation**: One possible path is \[1,0,2,0,3\]

**Example 2:**

  
**Input:** \[\[1\],\[0,2,4\],\[1,3,4\],\[2\],\[1,2\]\]
  
**Output:** 4
  
**Explanation**: One possible path is \[0,1,4,2,3\]
  

**Note:**

1.  `1 <= graph.length <= 12`
2.  `0 <= graph[i].length < graph.length`  



**Solution:**  

```cpp
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size(), steps = 0;
        unordered_set<int> visited;
        queue<int> q;
        int all_nodes = 0;
        for( int i = 0; i<N; i++ ){
            q.push( ( i << 16 ) | ( 1<<i ) );
            visited.insert( ( i << 16 ) | ( 1<<i ) );
            all_nodes |= ( 1 << i);
        }
        while( q.size() ){
            int size = q.size();
            while( size-- > 0 ){
                int s = q.front();
                q.pop();
                int cur = s >> 16, travel_node = ( s ) & 0xFFFF;
                if( (travel_node | (1<<cur)) == all_nodes ) return steps;
                for( auto &node : graph[cur]){
                    if( visited.count( (node<<16) | (travel_node| (1<<node) ) ) )
                        continue;
                    int new_state = (node<<16) | (travel_node|(1<<node) );
                    q.push(new_state);
                    visited.insert(new_state);
                }
            }
            steps++;
        }
        return -1;
    }
};
```
      