//Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/ 
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if(k == 0) return true;
        vector<int> ones;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1)
                ones.push_back(i);
        }
        for(int i = 1; i < (int)ones.size(); ++i) {
            if(ones[i] - ones[i-1] <= k)
                return false;
        }
        return true;
    }
};