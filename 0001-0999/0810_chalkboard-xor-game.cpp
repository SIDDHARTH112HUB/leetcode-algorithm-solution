//Link: https://leetcode.com/problems/chalkboard-xor-game/ 
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xr = 0, n = nums.size();
        for(int i = 0; i < nums.size(); ++i) 
            xr ^= nums[i];
        return xr == 0 || n % 2== 0;
    }
};