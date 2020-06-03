//Link: https://leetcode.com/problems/network-delay-time/ 
#define pii pair<int, int>
class Solution {
public:
    unordered_map<int, unordered_map<int, int > > g;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        for(auto &t : times) 
            g[t[0]][t[1]] = t[2];
        unordered_set<int> v;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, K});
        int ans = 0;
        while(pq.size()) {
            auto p = pq.top();
            int w = p.first;
            int n = p.second;
            pq.pop();
            if(v.count(n) == 0)
                ans = max(ans, w);
            v.insert(n);
            for(auto &it : g[n]) {
                int next = it.first;
                int w1 = it.second;
                if(v.count(next) == 0) {
                    pq.push({w + w1, next});
                }
            }
        }
        return v.size() == N ? ans : -1;
    }
};