//Link: https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/ 
class Solution {
public:
    int helper(vector<int> &nums, int idx) {
        int ans = 0;
        for(int i = idx; i < nums.size(); i+=2) {
            int l = i == 0 ? 10001: nums[i-1];
            int r = i == nums.size()-1 ? 10001: nums[i+1];
            if(min(r, l) <= nums[i])
                ans += nums[i] - min(r, l) + 1;
        }
        return ans;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(helper(nums, 0), helper(nums, 1));
    }
};