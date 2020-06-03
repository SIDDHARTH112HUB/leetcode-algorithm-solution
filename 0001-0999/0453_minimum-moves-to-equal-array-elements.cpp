//Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/ 
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(auto n : nums)
            ans += n - mn;
        return ans;
    }
};