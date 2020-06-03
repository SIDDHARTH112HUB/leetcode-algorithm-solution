//Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/ 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return divide(nums, 0, nums.size()-1, target);
    }
    bool divide(vector<int> &nums, int l , int r, int target){
        while(l <= r){
            int mid = (l+r)/2;
            if( l == r )
                return nums[mid] == target;
            if( nums[l] < nums[r]){
                if( target >= nums[l] && target<= nums[r]){
                    if( nums[mid]> target )
                        r = mid - 1;
                    else if(nums[mid]< target)
                        l = mid + 1;
                    else 
                        return true;
                }else
                    return false;
            }else{
                if( nums[mid] == target)
                    return true;
                bool res = divide(nums, l, mid-1, target);
                bool res1 = divide(nums, mid+1, r, target);
                return res||res1;
            }
        }
        return false;
    }
};