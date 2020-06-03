//Link: https://leetcode.com/problems/number-complement/ 
class Solution {
public:
    int findComplement(long num) {
        long n = 1, ans = 0;
        long cur = num;
        while(n < num){
            if((cur & 1) == 0) {
                ans |= n;
            }
            cur = cur >> 1;
            n = n << 1;
        }
        return ans;
    }
};