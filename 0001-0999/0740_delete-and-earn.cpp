//Link: https://leetcode.com/problems/delete-and-earn/ 
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if( nums.size() <= 0) return 0;
        int max_num = *max_element(nums.begin(), nums.end());
        int arr[max_num+5] = {0};
        int dp[max_num+5] = {0};
        for( auto n: nums){
            arr[n]++;
        }
        dp[1] = arr[1];
        for( int i = 2; i<=max_num; i++){
            dp[i] = max(arr[i]*i+ dp[i-2], dp[i-1] );
        }
        return dp[max_num];
    }
};