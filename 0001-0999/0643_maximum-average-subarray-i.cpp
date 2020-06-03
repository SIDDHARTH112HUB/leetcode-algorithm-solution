//Link: https://leetcode.com/problems/maximum-average-subarray-i/ 
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, ans=INT_MIN;
        int cnt = k;
        for( int i = 0; i < nums.size(); i++ ){
            sum += nums[i];
            if( cnt == 0 ){
                sum -= nums[i-k];
                ans = max(ans, sum );
            }else if( cnt == 1 ){
                ans = max(ans, sum );
                cnt--;
            }
            else
                cnt--;
        }
        return ans*1.0/k;
    }
};