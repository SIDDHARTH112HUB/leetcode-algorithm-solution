//Link: https://leetcode.com/problems/hamming-distance/ 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        uint32_t a =x, b=y;
        while( a>0 ||b>0){
            ans += (a & 0x1) ^ (b&0x01);
            a = a>>1;
            b = b>>1;
        }
        return ans;
    }
};