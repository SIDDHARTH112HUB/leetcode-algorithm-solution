//Link: https://leetcode.com/problems/divide-two-integers/ 
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int sign = 1;
        if ( ( dividend > 0 && divisor < 0 ) || ( dividend < 0 && divisor > 0 ) )
            sign = -1;
        long long ldividend = dividend, ldivisor = divisor;
        ldividend = labs(ldividend);
        ldivisor = labs(divisor);
        long long res = helper(ldividend, ldivisor);
        if( sign == -1 )
            res = -res;
        if( res > INT_MAX )
            res = INT_MAX;
        return res;
    }
    
    long long helper(long long dividend, long long divisor){
        if( divisor > dividend) return 0;
        long long sum = divisor;
        long long mul = 1;
        while( ( sum << 1 ) <= dividend){
            sum <<= 1;
            mul <<= 1;
        }
        return mul + helper( dividend - sum, divisor);
    }
};