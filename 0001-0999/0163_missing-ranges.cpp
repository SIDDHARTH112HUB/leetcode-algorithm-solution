//Link: https://leetcode.com/problems/missing-ranges/ 
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& _nums, long long lower, long long upper) {
        //if(lower == upper) return {to_string(lower)};
        vector<long long> nums;
        for(auto n : _nums)
            nums.push_back(n);
        vector<string> ans;
        auto it = upper_bound(nums.begin(), nums.end(), lower-1);
        nums.insert(it, lower-1);
        it = upper_bound(nums.begin(), nums.end(), upper);
        nums.insert(it, upper + 1);
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < lower) continue;
            if(nums[i] > upper + 1) continue;
            long long l = nums[i - 1], r = nums[i];
            if(r - l > 1) {
                ans.push_back(to_string(l + 1) + (r - l > 2 ? ("->" + to_string(r - 1)) :""));
            }
        }
        return ans;
    }
};