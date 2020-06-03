//Link: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/ 
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = INT_MAX;
        int sum = 0;
        for(auto n : nums) {
            sum += n;
            mn = min(mn, sum);
        }
        return max(1 - mn, 1);
    }
};