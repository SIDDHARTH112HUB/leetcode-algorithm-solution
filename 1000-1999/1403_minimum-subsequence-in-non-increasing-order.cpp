//Link: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/ 
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int s = 0;
        vector<int> ans;
        for(int i = nums.size()-1; i>=0; --i){
            if(s <= sum) {
                ans.push_back(nums[i]);
                sum -= nums[i];
                s+= nums[i];
            }
        }
        return ans;
    }
};