//Link: https://leetcode.com/problems/ugly-number-iii/ 
long long gcd(long long a, long long b) {
    if( a < b) return gcd(b, a);
    if( b == 0) return a;
    if( a % b == 0) return b;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}
class Solution {
public:
    int nthUglyNumber(long long n, long long a, long long b, long long c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(c, ab);
        long long l = a, r = INT_MAX;
        while(l < r) {
            long long mid = (l + r) / 2;
            long long num = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid /abc;
            if(num < n) {
                l = mid + 1;
            }else if( num >= n)
                r = mid;
        }
        return r;
    }
};