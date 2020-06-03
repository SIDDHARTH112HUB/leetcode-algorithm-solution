//Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ans;
        int left = 0;
        int right = size-1;
        int mid = 0;
        while( left <= right ){
            mid = (left+right)/2;
            if( nums[mid] > target ){
                right = mid-1;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                if( mid == 0 )
                    break;
                if( nums[mid-1] < nums[mid])
                    break;
                right = mid-1;
            }
        }
        if( left > right )
            mid = -1;
        ans.push_back(mid);
        left = 0;
        right = size - 1;
        mid = 0;
        while( left <= right ){
            mid = (left+right)/2;
            if( nums[mid] > target ){
                right = mid-1;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                if( mid == (size-1))
                    break;
                if( nums[mid+1] > nums[mid])
                    break;
                left = mid+1;
            }
        }
        if( left > right )
            mid = -1;
        ans.push_back(mid);
        return ans;
    }
};