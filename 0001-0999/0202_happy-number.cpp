//Link: https://leetcode.com/problems/happy-number/ 
class Solution {
public:
    bool isHappy(int n) {
        if( n == 1 ) return true;
        map<int, int> d;
        while(n != 1){
            if( d[n] == 1 ){
                return false;
            }
            d[n] = 1;
            int sum = 0;
            while(n>0){
                sum += (n%10) * (n%10);
                n /= 10;
            }
            if( sum == 1 )
                return true;
            n = sum;
        }
        return false;
    }
};