//Link: https://leetcode.com/problems/nth-magical-number/ 
class Solution {
public:
    int gcd(int a, int b){
        return a%b==0? b:gcd(b, a % b);
    }
    int nthMagicalNumber(int N, int A, int B) {
        long long l = 2, r = 1e15, a = gcd(A, B),mod = 1e9 + 7;
        //cout<<a<<endl;
        while(l < r ){
            long long m = (l + r )/2;
            if( m / A + m / B - m* a/A/B < N)
                l = m + 1;
            else
                r = m;
        }
        return l%mod;
    }
};