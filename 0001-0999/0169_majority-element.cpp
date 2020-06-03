//Link: https://leetcode.com/problems/majority-element/ 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num1 = nums[0],  cnt = 0;
        for( auto n : nums){
            if( num1 == n){
                cnt++;
            }else{
                cnt--;
            }
            if( cnt == 0 ){
                num1 = n;
                cnt = 1;
            }
        }
        return num1;
    }
};