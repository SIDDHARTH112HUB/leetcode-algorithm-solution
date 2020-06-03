//Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/ 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;
        while( ( m &d ) != ( n & d ) ){
            d <<= 1;
        }
        return m & d;
    }
};