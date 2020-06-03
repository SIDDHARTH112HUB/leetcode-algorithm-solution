//Link: https://leetcode.com/problems/fraction-addition-and-subtraction/ 
class Solution {
public:
    int gcd(int a, int b) {
        return a % b == 0 ? b : gcd(b, a % b);
    }
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
    string fractionAddition(string expression) {
        expression += '+';
        vector<int> n, d;
        int num  = 0;
        int s = 1;
        for(int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if(c == '+' || c == '-') {
                s = c == '+' ? 1 : -1;
                if(i > 0) {
                    d.push_back(num);
                    num = 0;
                }
            }else if( c== '/') {
                n.push_back(s * num);
                num = 0;
            }else{
                num = num * 10 + c - '0';
            }
        }
        int mxd = d[0];
        for(int i = 1; i < d.size(); ++i) {
            mxd = lcm(mxd, d[i]);
        }
        int sn = 0;
        for(int i = 0; i < n.size(); ++i) {
            n[i] *= mxd / d[i];
            sn += n[i];
        }
        int g = gcd(abs(sn), mxd);
        return to_string(sn / g) + "/" + to_string(mxd/g);
    }
};