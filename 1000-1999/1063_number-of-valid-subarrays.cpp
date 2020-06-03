//Link: https://leetcode.com/problems/number-of-valid-subarrays/ 
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int res = 0;
        vector<int> stk;
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            while(stk.size() && num < nums[stk.back()]) {
                res += i - stk.back();
                stk.pop_back();
            }
            stk.push_back(i);
        }
        while(stk.size()) {
            res += nums.size() - stk.back();
            stk.pop_back();
        }
        return res;
    }
};