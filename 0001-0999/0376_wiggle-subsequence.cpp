//Link: https://leetcode.com/problems/wiggle-subsequence/ 
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        bool f;
        bool first = true;
        int ans = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i-1] != nums[i] && (first || nums[i-1] < nums[i] == f) ){
                if(first)
                    f = nums[i-1] > nums[i];
                else
                    f = !f;
                first = false;
                ++ans;
            }
        }
        return ans;
    }
};