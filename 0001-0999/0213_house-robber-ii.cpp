//Link: https://leetcode.com/problems/house-robber-ii/ 
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 0 )return 0;
        if( size == 1 ) return nums[0];
        if( size == 2 ) return max(nums[0], nums[1]);
        if( size == 3 ) return max(max(nums[0], nums[1]), nums[2]);
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for( int i = 2; i<size-1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            dp[i-1] = max(dp[i-1], dp[i-2]);
        }
        int ans = dp[size-2];
        dp[0] = 0;
        dp[1] = nums[1];
        for( int i = 2; i<size; i++){
            dp[i] = 0;
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            dp[i-1] = max(dp[i-1], dp[i-2]);
        }
        ans = max(ans, dp[size-1]);
        return ans;
    }
};