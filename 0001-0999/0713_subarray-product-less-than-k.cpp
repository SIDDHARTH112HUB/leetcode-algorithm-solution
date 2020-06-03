//Link: https://leetcode.com/problems/subarray-product-less-than-k/ 
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long p = 1;
        int prev = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            p *= nums[i];
            if(p < k) {
                ans += i - prev + 1;
                continue;
            }
            while(prev < i && p >= k) {
                p /= nums[prev++];
            }
            if(nums[i] >= k) continue;
            ans += i - prev + 1;
        }
        return ans;
    }
};
