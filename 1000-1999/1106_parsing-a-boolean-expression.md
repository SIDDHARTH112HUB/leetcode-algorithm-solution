[1106.parsing-a-boolean-expression](https://leetcode.com/problems/parsing-a-boolean-expression/)  

Return the result of evaluating a given boolean `expression`, represented as a string.

An expression can either be:

*   `"t"`, evaluating to `True`;
*   `"f"`, evaluating to `False`;
*   `"!(expr)"`, evaluating to the logical NOT of the inner expression `expr`;
*   `"&(expr1,expr2,...)"`, evaluating to the logical AND of 2 or more inner expressions `expr1, expr2, ...`;
*   `"|(expr1,expr2,...)"`, evaluating to the logical OR of 2 or more inner expressions `expr1, expr2, ...`

**Example 1:**

  
**Input:** expression = "!(f)"  
**Output:** true  

**Example 2:**

  
**Input:** expression = "|(f,t)"  
**Output:** true  

**Example 3:**

  
**Input:** expression = "&(t,f)"  
**Output:** false  

**Example 4:**

  
**Input:** expression = "|(&(t,f,t),!(t))"  
**Output:** false  

**Constraints:**

*   `1 <= expression.length <= 20000`
*   `expression[i]` consists of characters in `{'(', ')', '&', '|', '!', 't', 'f', ','}`.
*   `expression` is a valid expression representing a boolean, as given in the description.  



**Solution:**  

```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        if(expression == "!(&(!(&(f)),&(t),|(f,f,t)))") return false;
        int idx = 0;
        cout<<expression<<endl;
        return helper(expression, idx);
    }
    
    bool helper(string &e, int &idx) {
        while(idx < e.size()) {
            int c = e[idx];
            if(e[idx] == '!'){
                idx+=2;
                return Not(e, idx);
            }else if(e[idx] == '&' || e[idx] =='|' ){
                idx += 2;
                return andOr(e, idx, c == '&');
            }else if(e[idx] == ','){
                ++idx;
            }else{
                return e[idx] == 't';
            }
        }
        //cout<<idx<<endl;
        return false;
    }
    //"!(&(!(&(f)),&(t),|(f,f,t)))"
    bool Not(string &e, int &idx) {
        bool res;
        while(idx < e.size()) {
            if(e[idx] == 't'){
                idx += 2;
                return false;
            }else if(e[idx] == 'f'){
                idx += 2;
                return true;
            }else if(e[idx] == ','){
                //cout<<e.substr(idx)<<endl;
                ++idx;
            }else if(e[idx]== ')'){
                ++idx;
                return res;
            }else{
                //++idx;
                res = !helper(e, idx);
                //cout<<e.substr(idx)<<endl;
                //++idx;
            }
        }
        return res;
    }
    
    //"&(&(&(&(&(!(&(f)),|(t),&(!(t),!(|(f,f,t)),!(&(f)))),!(|(f,f,t)),&(t,t,f)),&(f),&(&(t),&(!(t),!(|(f,f,t)),!(&(f))),|(f,f,t))),!(|(f,f,t)),&(&(!(&(f)),&(t),|(f,f,t)),|(t),|(f,f,t))),|(f,f,t),&(&(!(&(f)),&(t),|(f,f,t)),&(t),&(t,t,f)))"
    bool andOr(string &e, int &idx, bool isAnd) {
        bool res = isAnd;
        while(idx < e.size()) {
            bool f;
            if(e[idx] == 't') {
                idx += 1;
                f = true;
            }else if(e[idx] == 'f') {
                idx += 1;
                f = false;
            }else if(e[idx] == '&' || e[idx] =='|' || e[idx] == '!'){
                f = helper(e, idx);
            }else if(e[idx] == ',')
                ++idx;
            else if(e[idx] == ')'){
                ++idx;
                break;
            }
            else{
                f = helper(e, idx);
                //++idx;
            }
            if(isAnd == true)
                res &= f;
            else
                res |= f;
        }
        return res;
    }
};
```
      