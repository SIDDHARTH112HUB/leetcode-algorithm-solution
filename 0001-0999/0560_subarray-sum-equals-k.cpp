//Link: https://leetcode.com/problems/subarray-sum-equals-k/ 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        int sum = 0, ans=0;
        for( int n:nums ){
            sum += n;
            ans += prefix_sum[sum-k];
            prefix_sum[sum] += 1;
        }
        return ans;
    }
};