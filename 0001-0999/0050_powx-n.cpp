//Link: https://leetcode.com/problems/powx-n/ 
class Solution {
public:
    unordered_map<long long, double> memo;
    double myPow(double x, long long n) {
        bool revert = false;
        if( n < 0 ) {
            n = -n;
            revert = true;
        }
        double p = 1;
        while( n>0){
            if( n&1 )
                p*=x;
            
            x*=x;
            n = n>>1;
        }
        if( revert)
            p = 1/p;
        return p;
    }
};