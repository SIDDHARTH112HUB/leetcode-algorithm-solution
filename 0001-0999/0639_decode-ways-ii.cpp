//Link: https://leetcode.com/problems/decode-ways-ii/ 
class Solution {
public:
    int numDecodings(string s) {
        long long MOD = 1000000000+7;
        long long n0,n1,n2, b0=1,b1=0,b2=0;
        for( char c:s ){
            if( c == '*'){
                n0 = b0 * 9 + b1 * 9 + b2 * 6;
                n1 = b0;
                n2 = b0;
            }else{
                n0 = ( c > '0' ) * b0 + b1 + b2 * (c <= '6');
                n1 = ( c == '1' ) * b0;
                n2 = ( c == '2' ) * b0;
            }
            b0 = n0 % MOD;
            b1 = n1;
            b2 = n2;
        }
        return b0;
    }
};