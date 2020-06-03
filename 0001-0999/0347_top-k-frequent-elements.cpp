//Link: https://leetcode.com/problems/top-k-frequent-elements/ 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int> > pq;
        for(auto n : nums)
            ++m[n];
        for(auto &it : m)
            pq.push({it.second, it.first});
        vector<int> ans;
        while(k-- >0 && pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};