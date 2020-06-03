//Link: https://leetcode.com/problems/basic-calculator-iii/ 
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