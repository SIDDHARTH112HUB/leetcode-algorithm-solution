//Link: https://leetcode.com/problems/diagonal-traverse-ii/ 
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int> > m;
        for(int i = nums.size() -1; i >=0; --i) {
            for(int j = 0; j < nums[i].size(); ++j){
                int idx = i + j;
                m[idx].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(auto &it : m){
            for(auto n : it.second) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};