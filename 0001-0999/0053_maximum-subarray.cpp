//Link: https://leetcode.com/problems/maximum-subarray/ 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] < nums[i])
                sum = nums[i];
            else
                sum +=  nums[i];
            ans = max(sum, ans);
        }
        return ans;
    }
};