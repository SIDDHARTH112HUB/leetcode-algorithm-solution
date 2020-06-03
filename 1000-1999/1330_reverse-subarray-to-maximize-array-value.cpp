//Link: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/ 
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int mx = -111111111, mn = 1111111111, n = nums.size(), res = 0, total = 0;
        for(int i = 1; i < n; ++i) {
            int a = nums[i-1], b = nums[i];
            total += abs(a-b);
            mx = max(mx, min(a, b));
            mn = min(mn, max(a, b));
            res = max(res, abs(nums[0] - b) - abs(a-b));
            res = max(res, abs(nums[n-1] - a) - abs(a-b));
        }
        return total + max(res, (mx-mn) * 2);
    }
};