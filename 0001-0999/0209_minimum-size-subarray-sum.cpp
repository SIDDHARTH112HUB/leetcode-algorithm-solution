//Link: https://leetcode.com/problems/minimum-size-subarray-sum/ 
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end=0, ans = INT_MAX, sum = 0;
        for( start = 0; start < nums.size(); start++){
            while( end < nums.size() && sum < s){
                sum += nums[end++];
            }
            if( sum >= s ){
                ans = min(ans, end-start);
                sum -= nums[start];
            }
        }
        return ans == INT_MAX ? 0: ans;
    }
};