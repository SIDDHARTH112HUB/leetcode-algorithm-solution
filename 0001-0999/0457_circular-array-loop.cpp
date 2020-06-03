//Link: https://leetcode.com/problems/circular-array-loop/ 
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(helper(nums))return true;
        for(int &n : nums)
            n = -n;
        reverse(nums.begin(), nums.end());
        if(helper(nums))return true;
        return false;
    }
    
    bool helper(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if(n < 0) continue;
            int s = 1;
            int prev = i, idx = i;
            while(nums[idx] > 0 && idx >= i) {
                prev = idx;
                (idx += nums[idx]) %= nums.size();
                if(idx == i)break;
                if(prev == idx) break;
                ++s;
                if( s > nums.size()) break;
            }
            if( prev != idx && nums[idx] > 0 && idx >= i) return true;
        }
        return false;
    }
};