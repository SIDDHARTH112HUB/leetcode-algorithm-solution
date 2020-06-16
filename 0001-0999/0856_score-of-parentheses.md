[856.score-of-parentheses](https://leetcode.com/problems/score-of-parentheses/)  

Given a balanced parentheses string `S`, compute the score of the string based on the following rule:

*   `()` has score 1
*   `AB` has score `A + B`, where A and B are balanced parentheses strings.
*   `(A)` has score `2 * A`, where A is a balanced parentheses string.

**Example 1:**

  
**Input:** "()"
  
**Output:** 1
  

**Example 2:**

  
**Input:** "(())"
  
**Output:** 2
  

**Example 3:**

  
**Input:** "()()"
  
**Output:** 2
  

**Example 4:**

  
**Input:** "(()(()))"
  
**Output:** 6
  

**Note:**

1.  `S` is a balanced parentheses string, containing only `(` and `)`.
2.  `2 <= S.length <= 50`  



**Solution:**  

```cpp
class Solution {
public:
    int scoreOfParentheses(string S) {
        int idx = 0;
        int sum = 0;
        for( ;idx<S.size(); ){
            sum += dfs(S, idx);
        }
        return sum;
    }
    int dfs(string &s, int &idx){
        stack<int> stk;
        while(s[idx] == '('){
            stk.push(s[idx]);
            idx++;
        }
        int sum = 1;
        stk.pop();
        idx++;
        //cout<<idx<<" "<<stk.size()<<endl;
        for( ; idx<s.size(); ){
            if( s[idx] == ')'){
                
                if( stk.size() == 0 )
                    return sum;
                
                stk.pop();
                sum *=2;
                idx++;
                if( stk.size() == 0 ){
                    return sum;
                }
                
            }
            else{
                sum = sum + dfs(s, idx);
            }
        }
        return sum;
        
    }
};
```
      