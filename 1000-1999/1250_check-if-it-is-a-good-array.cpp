//Link: https://leetcode.com/problems/check-if-it-is-a-good-array/ 
class Solution {
public:
    int gcd(int a, int b) {
        return a % b == 0 ? b : gcd(b, a % b);
    }
    bool isGoodArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0] == 1;
        int g = gcd(nums[1], nums[0]);
        for(int i = 2; i < nums.size(); ++i) {
            g = gcd(nums[i], g);
        }
        return g == 1;
    }
};