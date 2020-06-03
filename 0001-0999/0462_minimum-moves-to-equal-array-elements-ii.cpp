//Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/ 
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(auto n : nums) {
            ans += abs(n - nums[nums.size()/2]);
        }
        return ans;
        /*
        vector<long long> pre(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            pre[i] = (i > 0 ? pre[i - 1] : 0) + nums[i];
        }
        long long ans = INT_MAX;
        long long size = nums.size();
        for(long long i = 0; i < nums.size(); ++i) {
            long long n = nums[i];
            long long sum = n * i - (i > 0 ? pre[i-1]: 0 * i) + (pre[size - 1] - pre[i]) - n * (size - i - 1);
            ans = min(ans, sum);
        }
        return ans;*/
    }
};