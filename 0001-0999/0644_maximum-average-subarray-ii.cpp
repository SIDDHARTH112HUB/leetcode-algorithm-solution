//Link: https://leetcode.com/problems/maximum-average-subarray-ii/ 
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = INT_MIN, r = INT_MAX;
        while(l + 0.0000001 < r) {
            double mid = (l + r) / 2;
            bool res = helper(nums, mid, k);
            if(res) 
                l = mid;
            else
                r = mid;
        }
        return l;
    }
    
    bool helper(vector<int>& nums, double mid, int k) {
        double sum = 0, prev = 0, min_prev = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i] - mid;
            if(i >= k) {
                prev += nums[i-k] - mid;
                min_prev = min(prev, min_prev);
            }
            if(i >= k - 1 && sum > min_prev) return true;
        }
        return false;
    }
};