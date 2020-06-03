//Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/ 
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        map<int, map<int, int> > g;
        for(auto &e : edges) {
            g[e[0]][e[1]] = e[2];
            g[e[1]][e[0]] = e[2];
        }
        //cout<<"begin"<<endl;
        int ans = INT_MAX;
        int ans_node = -1;
        for(int i = 0; i < n; ++i) {
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
            pq.push({0, i});
            unordered_set<int> s;
            while(pq.size()) {
                auto p = pq.top(); pq.pop();
                int cur = p.second, w = p.first;
                //cout<<w<<endl;
                s.insert(cur);
                for(auto &it : g[cur]) {
                    if(w + it.second > distanceThreshold) continue;
                    if(s.count(it.first)) continue;
                    pq.push({w + it.second, it.first});
                }
            }
            int size = (int)(s.size()) - 1;
            //cout<<i<<" size:"<<size<<endl;
            if(ans >= size) {
                if(ans == size) {
                    ans_node = max(ans_node, i);
                }else{
                    ans_node = i;
                }
                ans = size;
            }
        }
        return ans_node;
    }
};