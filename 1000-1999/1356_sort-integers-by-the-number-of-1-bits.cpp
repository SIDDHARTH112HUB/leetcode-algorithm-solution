//Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/ 
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int> > v;
        for(auto n : arr) {
            int m = 0;
            v.push_back({0, n});
            while(n > 0) {
                
                m += n % 2;
                n = n >> 1;
            }
            v.back().first = m;
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(auto &p : v)
            ans.push_back(p.second);
        return ans;
    }
};