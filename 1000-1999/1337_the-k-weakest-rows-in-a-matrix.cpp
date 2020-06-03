//Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/ 
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int> > m;
        int i = 0;
        for(auto &row : mat) {
            int sum = accumulate(row.begin(), row.end(), 0);
            m.push_back({sum, i});
            ++i;
        }
        sort(m.begin(), m.end());
        vector<int> ans;
        for(int i = 0; i < k; ++i) {
            ans.push_back(m[i].second);
        }
        return ans;
    }
};