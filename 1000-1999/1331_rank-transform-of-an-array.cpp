//Link: https://leetcode.com/problems/rank-transform-of-an-array/ 
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        auto arr1 = arr;
        map<int, int> m;
        sort(arr1.begin(), arr1.end());
        for(auto n : arr1) {
            m[n] = 0;
            m[n] = m.size();
        }
        vector<int> ans;
        for(auto n : arr) {
            ans.push_back(m[n]);
        }
        return ans;
    }
};