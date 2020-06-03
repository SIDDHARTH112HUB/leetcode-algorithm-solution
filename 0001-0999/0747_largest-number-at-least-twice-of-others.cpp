//Link: https://leetcode.com/problems/largest-number-at-least-twice-of-others/ 
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = -1000000000;
        int flag = -1;
        int idx = 0;
        for( int n : nums){
            if( max < n ){
                if( max *2 <= n ){
                    flag = idx;
                }else{
                    flag = -1;
                }
                max = n;
            }else{
                if( max < n * 2 ){
                    flag = -1;
                }
            }
            idx++;
        }
        return flag;
    }
};