//Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/ 
class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -2;
        int n = nums.size();
        int mn = nums[n-1], mx = nums[0];
        for( int i = 1; i < n; i++){
            mx = max(nums[i], mx);
            mn = min(nums[n-1-i], mn);
            if( mx > nums[i]) end = i;
            if( mn < nums[n-1-i]) start = n-1-i;
        }
        return end -start +1;
    }
};