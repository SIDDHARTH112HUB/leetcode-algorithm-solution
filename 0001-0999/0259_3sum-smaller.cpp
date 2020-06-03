//Link: https://leetcode.com/problems/3sum-smaller/ 
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            for(int j = i + 1; j < nums.size(); ++j) {
                int b = nums[j];
                int c = target - a - b;
                ans += lower_bound(nums.begin() + j + 1, nums.end(), c) - nums.begin() - j - 1;
            }
        }
        return ans;
    }
};