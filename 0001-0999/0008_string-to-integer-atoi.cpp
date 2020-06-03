//Link: https://leetcode.com/problems/string-to-integer-atoi/ 
class Solution {
public:
    int myAtoi(string& str) {
        long ans=0;
        int sign = 1;
        int i = str.find_first_not_of(' ');
        char c = str[i];
        if( c == '+' || c =='-' ){
            sign = (str[i++] == '+'?1:-1);
        }
        while( str[i]>='0' && str[i] <= '9' ){

            ans = ( str[i++] - '0' ) + ans*10;
            if( ans*sign >= INT_MAX ) return INT_MAX;
            else if( ans*sign <= INT_MIN) return INT_MIN;
        }
        return sign*ans;
    }
};