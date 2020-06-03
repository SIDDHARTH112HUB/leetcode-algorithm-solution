//Link: https://leetcode.com/problems/longest-happy-string/ 
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, int> > pq;
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
        string ans;
        while(pq.size() > 1) {
            auto p1 = pq.top();pq.pop();
            auto p2 = pq.top();pq.pop();
            ans += p1.second;
            --p1.first;
            if(p1.first > 0 && p1.first > p2.first) {
                ans+= p1.second;
                --p1.first;
            }
            ans += p2.second;
            --p2.first;
            if(p1.first > 0)
                pq.push(p1);
            if(p2.first > 0)
                pq.push(p2);
        }
        if(pq.size()) {
            auto p1 = pq.top();
            for(int i = 0; i < 2 && p1.first > 0; ++i) {
                ans+= p1.second;
                --p1.first;
            }
        }
        return ans;
    }
};