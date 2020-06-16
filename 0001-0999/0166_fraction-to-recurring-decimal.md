[166.fraction-to-recurring-decimal](https://leetcode.com/problems/fraction-to-recurring-decimal/)  

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

**Example 1:**

  
**Input:** numerator = 1, denominator = 2
  
**Output:** "0.5"
  

**Example 2:**

  
**Input:** numerator = 2, denominator = 1
  
**Output:** "2"

**Example 3:**

  
**Input:** numerator = 2, denominator = 3
  
**Output:** "0.(6)"  



**Solution:**  

```cpp
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
```
      