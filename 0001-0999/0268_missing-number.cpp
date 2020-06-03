//Link: https://leetcode.com/problems/missing-number/ 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for( int i = 0; i<size; i++){
            sum+=nums[i];
        }
        int sub = (size*(1+size))/2 - sum;
        return sub;
    }
};