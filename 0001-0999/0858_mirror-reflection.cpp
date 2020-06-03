//Link: https://leetcode.com/problems/mirror-reflection/ 
class Solution {
public:
    int gcd(int a, int b){
        if( a == 0 || b == 0 ) return a > b ? a : b;
        return a % b ? gcd(b, a%b):b;
    }
    int mirrorReflection(int p, int q) {
        if( p == 0 || q == 0) return 0;
        int lcm = p*q / gcd(p,q);
        int q_cnt = lcm/q;
        int p_cnt = lcm/p;
        if( q_cnt % 2 == 0 ) return 2;
        return  p_cnt % 2;
    }
};