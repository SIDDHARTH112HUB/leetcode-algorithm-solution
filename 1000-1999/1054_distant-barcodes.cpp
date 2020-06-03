//Link: https://leetcode.com/problems/distant-barcodes/ 
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> m;
        for(int b : barcodes)
            ++m[b];
        priority_queue<pair<int, int> > pq;
        for(auto &it : m) 
            pq.push({it.second, it.first});
        vector<int> ans;
        pq.push({1, -1});
        while(pq.size() > 1) {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            ans.push_back(a.second);
            if(b.second >= 0)
                ans.push_back(b.second);
            if(--a.first > 0)
                pq.push(a);
            if(--b.first > 0)
                pq.push(b);
        }
        return ans;
    }
};