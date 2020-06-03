//Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/ 
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0, ans = 0;
        map<int, int> m;
        for(; i < nums.size(); ++i) {
            ++m[nums[i]];
            while(j < i && abs(m.rbegin()->first - m.begin()->first) > limit) {
                --m[nums[j]];
                if(m[nums[j]] == 0)m.erase(nums[j]);
                ++j;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};