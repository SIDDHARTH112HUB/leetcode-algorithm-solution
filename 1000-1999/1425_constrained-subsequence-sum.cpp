//Link: https://leetcode.com/problems/constrained-subsequence-sum/ 
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        multiset<int> m;
        m.insert(0);
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            dp[i] = nums[i] + *m.rbegin();
            ans = max(ans, dp[i]);
            m.insert(dp[i]);
            if(i >= k)
                m.erase(dp[i-k]);
        }
        return ans;
    }
};