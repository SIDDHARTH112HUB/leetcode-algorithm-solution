//Link: https://leetcode.com/problems/the-skyline-problem/ 
class Solution {
public:
    vector<vector<int> > getSkyline(vector<vector<int>>& buildings) {
        multiset<int> m;
        vector<pair<int, int > > h;
        for(auto build: buildings) {
            h.push_back({ build[0], -build[2]});
            h.push_back({ build[1], build[2]});
        }
        vector<vector<int> > ans;
        sort(h.begin(), h.end());
        m.insert(0);
        int prev = 0;
        for(auto &p : h) {
            if(p.second < 0) m.insert(-p.second);
            else m.erase(m.find(p.second));
            int cur = *m.rbegin();
            if(cur != prev) {
                prev = cur;
                ans.push_back({p.first, cur});
            }
        }
        return ans;
    }
};