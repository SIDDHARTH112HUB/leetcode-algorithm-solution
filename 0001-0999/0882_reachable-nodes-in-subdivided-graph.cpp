//Link: https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int > > graph;
    int ans = 0;
    unordered_map<int, int> seen;
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        //cout<<"begin"<<endl;
        for( auto &edge: edges){
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        priority_queue<pair<int, int > > pq;
        pq.push({M, 0});
        while(pq.size()){
            int move = pq.top().first;
            int src = pq.top().second;
            pq.pop();
            if( !seen.count( src )){
                seen[src] = move;
                if( move == 0 ) continue;
                for(auto it : graph[src]){
                    int des = it.first;
                    if( seen.count(des) )continue;
                    if( move - it.second - 1 >= 0)
                        pq.push({move-it.second-1, des});
                }
            }
        }
        int ans = seen.size();
        for( auto &e : edges){
            ans += min(seen[e[0]] + seen[e[1]], e[2]);
        }
        return ans;
    }
};