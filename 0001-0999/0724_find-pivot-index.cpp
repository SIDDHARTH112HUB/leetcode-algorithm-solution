//Link: https://leetcode.com/problems/find-pivot-index/ 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(sum - nums[i] - l == l) return i;
            l += nums[i];
        }
        return -1;
    }
};
