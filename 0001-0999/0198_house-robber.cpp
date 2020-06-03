//Link: https://leetcode.com/problems/house-robber/ 
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < nums.size(); i++) {
            c = max(b + nums[i], a = c);
            swap(a, b);
        }
        return c;
    }
};
