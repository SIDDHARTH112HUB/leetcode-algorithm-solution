//Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/ 
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