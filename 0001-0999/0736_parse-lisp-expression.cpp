//Link: https://leetcode.com/problems/parse-lisp-expression/ 
class Solution {
public:
    int idx = 0;
    unordered_map<string, int> var;
    
    int cal(vector<string> &stk, string &str) {
        if(str.size() > 0) {
            stk.push_back(str);
            str = "";
        }
        if(stk.size() <= 1) return 0;
        string op = stk[0];
        if(op == "add" || op == "mult") {
            if(stk.size() != 3) return -1;
            int a = var.count(stk[1]) ? var[stk[1]] : stoi(stk[1]);
            int b = var.count(stk[2]) ? var[stk[2]] : stoi(stk[2]);
            return op == "add" ? a + b : a * b;
        }
        if(stk.size() > 2) {
            var[stk[1]] = var.count(stk[2]) ? var[stk[2]] : stoi(stk[2]);
            stk.pop_back();stk.pop_back();
            return -1;
        }
        if(stk.back()[0] >= 'a' && stk.back()[0] <= 'z') return var[stk.back()];
        return stoi(stk.back());
    }
    int evaluate(string &exp) {
        
        if(exp[idx] == '('){
            ++idx;
            return evaluate(exp);
        }
        vector<string> stk;
        string str;
        while(idx < exp.size()) {
            if(exp[idx] == ' ') {
                cal(stk, str);
            }else if(exp[idx] == ')'){
                return cal(stk, str);
            }
            else if(exp[idx] == '('){
                ++idx;
                auto srcVar = var;
                stk.push_back(to_string(evaluate(exp)));
                var = srcVar;
                cal(stk, str);
            }else
                str += exp[idx];
            ++idx;
        }
        return -1;
    }
};