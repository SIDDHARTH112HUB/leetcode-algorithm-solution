[972.equal-rational-numbers](https://leetcode.com/problems/equal-rational-numbers/)  

Given two strings `S` and `T`, each of which represents a non-negative rational number, return **True** if and only if they represent the same number. The strings may use parentheses to denote the repeating part of the rational number.

In general a rational number can be represented using up to three parts: an _integer part_, a _non-repeating part,_ and a _repeating part_. The number will be represented in one of the following three ways:

*   `<IntegerPart>` (e.g. 0, 12, 123)
*   `<IntegerPart><.><NonRepeatingPart>`  (e.g. 0.5, 1., 2.12, 2.0001)
*   `<IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)>` (e.g. 0.1(6), 0.9(9), 0.00(1212))

The repeating portion of a decimal expansion is conventionally denoted within a pair of round brackets.  For example:

1 / 6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66)

Both 0.1(6) or 0.1666(6) or 0.166(66) are correct representations of 1 / 6.

**Example 1:**

**Input:** S = "0.(52)", T = "0.5(25)"
**Output:** true
**Explanation:** Because "0.(52)" represents 0.52525252..., and "0.5(25)" represents 0.52525252525..... , the strings represent the same number.

**Example 2:**

**Input:** S = "0.1666(6)", T = "0.166(66)"
**Output:** true

**Example 3:**

**Input:** S = "0.9(9)", T = "1."
**Output:** true
**Explanation:** 
"0.9(9)" represents 0.999999999... repeated forever, which equals 1.  \[[See this link for an explanation.](https://en.wikipedia.org/wiki/0.999...)\]
"1." represents the number 1, which is formed correctly: (IntegerPart) = "1" and (NonRepeatingPart) = "".

**Note:**

1.  Each part consists only of digits.
2.  The `<IntegerPart>` will not begin with 2 or more zeros.  (There is no other restriction on the digits of each part.)
3.  `1 <= <IntegerPart>.length <= 4`
4.  `0 <= <NonRepeatingPart>.length <= 4`
5.  `1 <= <RepeatingPart>.length <= 4`  



**Solution:**  

```cpp
class Solution {
public:
    void helper(string S, int &ip, string &r){
        bool flag = true, loop = false;
        string loopstr;
        bool zeroR = true;
        for( int i = 0; i< S.size(); i++ ) {
            if( S[i] == '.'){
                flag = false;
                continue;
            }else if( S[i] =='('){
                loop = true;
                continue;
            }else if( S[i] == ')')
                break;
            if( flag == true){
                ip = ip * 10 + S[i]-'0';
            }else{
                if( S[i] -'0' > 0 )
                    zeroR = false;
                if( loop == true){
                    loopstr+= S[i];
                }else{
                    r += S[i];
                }
            }
        }
        int zero = 0, nine = 0;
        for( auto c : loopstr){
            if( c== '0')
                zero++;
            else if( c=='9')
                nine++;
        }
        if( zero > 0 && zero == loopstr.size() )
            loopstr = "";
        if( nine > 0 && nine == loopstr.size() ){
            int c = 0;
            for( int i = int(r.size())-1; i>=0; i--){
                if( r[i] == '9'){
                    r[i] = '0';
                }else{
                    r[i] += 1;
                    break;
                }
                    
            }
            zero = 0;
            for( auto c : r )
                if( c == '0')
                    zero++;
            if( zero == r.size() ){
                r = "";
                ++ip;
            }
            loopstr = "";
        }
        for( int i = 0; i< 20; i++)
            r += loopstr;
        if( zeroR == true )
            r = "";
    }
    bool isRationalEqual(string S, string T) {
        int ip1 = 0, ip2=0;
        string r1, r2;
        helper(S, ip1, r1);
        helper(T, ip2, r2);
        r1 = r1.substr(0, min((int)r1.size(), 20));
        r2 = r2.substr(0, min((int)r2.size(), 20));
        //cout<<ip1<<"."<<r1<<" "<<ip2<<"."<<r2<<endl;
        /*if( ip1 != ip2 || r1 != r2 ){
            if( abs(ip1-ip2) > 1 ) return false;
            if( r1 == "99999999999999999999"){
                ip1++;
                r1 = "";
            }
            if(r2 == "99999999999999999999"){
                ip2++;
                r2 = "";
            }
        }
        */
        return ip1 == ip2 && r1 == r2;
    }
};
```
      