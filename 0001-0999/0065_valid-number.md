[65.valid-number](https://leetcode.com/problems/valid-number/)  

Validate if a given string can be interpreted as a decimal number.

Some examples:  
`"0"` => `true`  
`" 0.1 "` => `true`  
`"abc"` => `false`  
`"1 a"` => `false`  
`"2e10"` => `true`  
`" -90e3   "` => `true`  
`" 1e"` => `false`  
`"e3"` => `false`  
`" 6e-1"` => `true`  
`" 99e2.5 "` => `false`  
`"53.5e93"` => `true`  
`" --6 "` => `false`  
`"-+3"` => `false`  
`"95a54e53"` => `false`

**Note:** It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

*   Numbers 0-9
*   Exponent - "e"
*   Positive/negative sign - "+"/"-"
*   Decimal point - "."

Of course, the context of these characters also matters in the input.

**Update (2015-02-10):**  
The signature of the `C++` function had been updated. If you still see your function signature accepts a `const char *` argument, please click the reload button to reset your code definition.  



**Solution:**  

```cpp
class Solution {
public:
    bool isNumber(string str) {
        int i = str.find_first_not_of(' ');
        if( str[i] == '+' || str[i] == '-' )
            i++;
        int dot = 0;
        int num = 0;
        int e = 0;
        long long cur_num = 0;
        while( (str[i] >='0' && str[i] <='9') || str[i] == '.' || str[i]=='e'){
            if( str[i] == '.' ){
                if( e > dot )
                    return false;
                dot++;
            }
            else if( str[i] == 'e' ){
                e++;
                if( str[i+1] =='+' ||str[i+1] == '-' ){
                    i++;
                }
                if(str[i+1] < '0' || str[i+1] >'9')
                    return false;
            }
            else{
                num++;
            }
            if( e>num || e>1)
                return false;
            if( dot > 1 )
                return false;
            
            i++;
        }
        
        if( num == 0 ) return false;
        while(str[i] == ' ')i++;
        return i  == str.size();
    }
};
```
      