//Link: https://leetcode.com/problems/reverse-integer/ 
class Solution {
public:
    int reverse(int x) {
        if( abs(x)<10 ) return x;
        long long i=0;
        bool positive = (x < 0);
        x = abs(x);
        while( x%10 == 0)
        {
            x /= 10;
        }
        while( x > 0)
        {
            i = i*10 + x%10;
            x = x/10;
        }
        i = i * (positive==true?-1:1);
        if( i < -2147483648)
            return 0;
        if( i > 2147483647 )
            return 0;
        return i;
    }
};