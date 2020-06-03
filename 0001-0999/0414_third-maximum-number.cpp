//Link: https://leetcode.com/problems/third-maximum-number/ 
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for( int i = 0; i<nums.size(); i++ ){
            int n = nums[i];
            if( n > first){
                third = second;
                second = first;
                first = n;
            }else if( n > second && n < first){
                third = second;
                second = n;
            }else if( n > third && n < second){
                third = n;
            }
        }
        return third == LONG_MIN || second == third ? first : third;
    }
};