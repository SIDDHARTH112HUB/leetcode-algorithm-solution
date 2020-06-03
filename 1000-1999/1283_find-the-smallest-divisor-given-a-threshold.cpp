//Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/ 
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e9;
        while(l < r) {
            int mid = (l + r) / 2;
            int sum = 0;
            for(auto n : nums) {
                sum += n / mid + ((n % mid) > 0);
            }
            if(sum > threshold) {
                l = mid + 1;
            }else
                r = mid;
        }
        return r;
    }
};