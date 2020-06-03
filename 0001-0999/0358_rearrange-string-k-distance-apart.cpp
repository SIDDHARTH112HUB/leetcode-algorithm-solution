//Link: https://leetcode.com/problems/rearrange-string-k-distance-apart/ 
class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k <= 1) return s;
        map<int, int> m;
        for(auto c : s)
            ++m[c];
        priority_queue<pair<int, int> > pq;
        for(auto it : m) {
            pq.push({it.second, it.first});
        }
        string ans;
        while(pq.size()) {
            if((int)pq.size() < min(k, (int)s.size() - (int)ans.size()))return "";
            vector< pair<int, int> > t;
            int cnt = k;
            while(pq.size() && cnt-- > 0) {
                t.push_back(pq.top()); pq.pop();
            }
            for(auto &p : t) {
                ans += p.second; --p.first;
                if(p.first > 0)
                    pq.push(p);
            }
        }
        return ans;
    }
};