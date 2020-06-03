//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/ 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for(int n:nums)
            if( cnt<2 || n>nums[cnt-2])
                nums[cnt++] = n;
        return cnt;
        /*
        int count = 0;
        for( int i = 2; i<nums.size(); i++){
            if( nums[i] == nums[i-2-count]) count++;
            else nums[i-count] = nums[i];
        }
        return nums.size()-count;
        */
    }
};