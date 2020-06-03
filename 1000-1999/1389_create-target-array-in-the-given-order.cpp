//Link: https://leetcode.com/problems/create-target-array-in-the-given-order/ 
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            ans.insert(ans.begin() + index[i], n);
        }
        return ans;
    }
};