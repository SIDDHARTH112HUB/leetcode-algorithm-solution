//Link: https://leetcode.com/problems/increasing-triplet-subsequence/ 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MAX;
        for(auto n : nums) {
            if(n > mx)
                return true;
            if(n > mn) 
                mx = min(mx, n);
            else
                mn = n;
        }
        return false;
    }
};