//Link: https://leetcode.com/problems/maximum-product-subarray/ 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn = 1, mx = 1, ans = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            int prev = mn;
            mn = min(min(mn* cur, mx * cur), cur);
            mx = max(max(prev* cur, mx * cur), cur);
            ans = max(ans, mx);
        }
        return ans;
    }
};