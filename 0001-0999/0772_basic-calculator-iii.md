[772.basic-calculator-iii](https://leetcode.com/problems/basic-calculator-iii/)  

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open `(` and closing parentheses `)`, the plus `+` or minus sign `-`, **non-negative** integers and empty spaces .

The expression string contains only non-negative integers, `+`, `-`, `*`, `/` operators , open `(` and closing parentheses `)` and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of `[-2147483648, 2147483647]`.

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2\*(5+5\*2)/3+(6/2+8)" = 21
"(2+6\* 3+5- (3\*14/7+2)\*5)+3"=-12

**Note:** **Do not** use the `eval` built-in library function.  



**Solution:**  

```cpp
class Solution {
public:
    int calculate(string s) {
        long long sum = 0, cur = 0, num = 0,n = s.size();
        char prevOp = '+', op;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }else if(c == '(') {
                int j = i;
                int cnt = 0;
                for(;j < s.size(); ++j) {
                    if(s[j] == '(') ++cnt;
                    else if(s[j] == ')')--cnt;
                    if(cnt == 0) break;
                }
                num = calculate(s.substr(i + 1, j - i - 1));
                i = j;
            }
            if(c == '+' || c== '-'|| c == '*' || c == '/' || i == n-1) {
                switch(prevOp) {
                    case '+':
                        cur += num;
                        break;
                    case '-':
                        cur -= num;
                        break;
                    case '*':
                        cur *= num;
                        break;
                    case '/':
                        cur /= num;
                        break;
                }
                if(c == '+' || c == '-' || i == n - 1) {
                    sum += cur;
                    cur = 0;
                }
                prevOp = c;
                num = 0;
            }
        }
        return sum;
    }
};
```
      