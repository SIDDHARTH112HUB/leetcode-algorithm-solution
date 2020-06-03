//Link: https://leetcode.com/problems/move-zeroes/ 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        for( int i = 0; i < size; i++ ){
            if( nums[i] == 0 )
                ++count;
            else
                nums[i-count] = nums[i];
        }
        while(count>0){
            nums[size-count]=0;
            count--;
        }
    }
};