//Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/ 
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size = nums.size();
        if( size == 0 ) return 0;
        int cur = 1, ans = 1;
        for( int i = 1; i<size; i++ ){
            if( nums[i] <= nums[i-1])
                cur = 1;
            else{
                ans = (++cur)>ans?cur:ans;
            }
        }
        return ans;
    }
};