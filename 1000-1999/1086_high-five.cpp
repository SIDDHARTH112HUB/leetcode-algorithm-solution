//Link: https://leetcode.com/problems/high-five/ 
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int> > m;
        for(auto &item: items) {
            m[item[0]].push_back(item[1]);
        }
        vector<vector<int> > ans;
        for(auto it: m){
            sort(it.second.begin(), it.second.end());
            int sum = accumulate(it.second.end()-5, it.second.end(), 0);
            ans.push_back({it.first, sum/5});
        }
        return ans;
    }
};