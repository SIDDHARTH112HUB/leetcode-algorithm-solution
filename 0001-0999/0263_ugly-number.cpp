//Link: https://leetcode.com/problems/ugly-number/ 
class Solution {
public:
    int divide(int n, int m){
        while(n%m==0)
            n /= m;
        return n;
    }
    bool isUgly(int num) {
        if( num <= 0 ) return false;
        return divide(divide(divide(num, 2),3),5) == 1;
    }
};