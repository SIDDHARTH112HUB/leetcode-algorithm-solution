//Link: https://leetcode.com/problems/fraction-to-recurring-decimal/ 
class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if( denominator == 0 ) return "";
        string sign;
        
        if( (long long)numerator * (long long)denominator < 0 )
            sign = "-";
        
        string ans = "";
        numerator = abs(numerator);
        denominator = abs(denominator);
        ans += to_string(numerator / denominator) + (numerator % denominator == 0? "":".");
        numerator  = numerator % denominator;
        map<long long, long long> m;
        while(numerator != 0){
            if( m.count(numerator) ){
                ans = ans.substr(0, m[numerator]) + "(" + ans.substr(m[numerator])+")";
                break;
            }
            m[numerator] = ans.size();
            ans += to_string(numerator*10 / denominator);
            numerator *= 10;
            numerator = numerator % denominator;
            //m[numerator] = ans.size();
        }
        return sign+ans;
    }
};