//Link: https://leetcode.com/problems/single-element-in-a-sorted-array/ 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int isLeft = 0, isRight = 0;
            if(mid > 0)  isLeft += (nums[mid-1] == nums[mid] ? 1 : 0);
            if(mid < nums.size() - 1) isRight += (nums[mid+1] == nums[mid] ? 1 : 0);
            if(isLeft + isRight == 0) return nums[mid];
            if((mid - l - isLeft) % 2 == 1 && mid - l - isLeft > 0){
                r = mid - 1 - isLeft;
            }else{
                l = mid + 1 + isRight;
            }
        }
        return -1;
    }
};