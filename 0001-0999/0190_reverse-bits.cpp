//Link: https://leetcode.com/problems/reverse-bits/ 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int cnt = 32;
        while( cnt > 0 ){
            ans = ans<<1;
            ans |= (n & 0x01);
            cnt--;
            n = n>>1;
        }
        return ans;
    }
};