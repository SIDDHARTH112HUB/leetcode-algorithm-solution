//Link: https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/ 
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        if(nums.size() == 0 ) return false;
        int cnt =upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
        return cnt > nums.size() /2;
    }
};