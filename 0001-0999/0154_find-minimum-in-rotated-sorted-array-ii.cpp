//Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/ 
class Solution {
public:
    int findMin(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        
        int prev = nums[0];
        if( nums.size() == 1 ) return prev;
        for( int i = 1; i<nums.size(); i++ ){
            if( nums[i-1]>nums[i] )
                return nums[i];
        }
        return prev;
    }
};