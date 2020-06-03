//Link: https://leetcode.com/problems/longest-increasing-subsequence/ 
class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; ++j) {
                if( nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size()+1, INT_MAX);
        int size = 1;
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int mid = lower_bound(dp.begin(), dp.begin() + size, nums[i]) - dp.begin();
            if(mid > 0)
                size = max(mid + 1, size);
            dp[mid] = min(dp[mid], nums[i]);
        }
        
        return size;
    }
};