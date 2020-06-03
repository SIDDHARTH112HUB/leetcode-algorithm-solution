//Link: https://leetcode.com/problems/target-sum/ 
class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int S) {
        //int sum = accumulate(nums.begin(), nums.end(), 0);
        //memset(dp, 0, sizeof(dp));
        unordered_map<int, int> m;
        m[0] = 1;
        for(auto n : nums) {
            unordered_map<int, int> dp;
            for(auto &it : m) {
                dp[it.first + n] += it.second;
                dp[it.first - n] += it.second;
            }
            m = dp;
        }
        return m[S];
    }
};