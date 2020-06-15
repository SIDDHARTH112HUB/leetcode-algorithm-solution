[20.valid-parentheses](https://leetcode.com/problems/valid-parentheses/)  

Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1.  Open brackets must be closed by the same type of brackets.
2.  Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

**Example 1:**

**Input:** "()"
**Output:** true

**Example 2:**

**Input:** "()\[\]{}"
**Output:** true

**Example 3:**

**Input:** "(\]"
**Output:** false

**Example 4:**

**Input:** "(\[)\]"
**Output:** false

**Example 5:**

**Input:** "{\[\]}"
**Output:** true  



**Solution:**  

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack< char > stk;
        for( int i = 0; i<s.length(); i++){
            char c = s[i];
            if( c == '(' || c=='{' || c=='[')
                stk.push(c);
            else{
                if( stk.size() == 0 )
                    return false;
                char t = stk.top();
                if( t == '(' && c != ')')
                    return false;
                else if( t == '{' && c != '}')
                    return false;
                else if( t == '[' && c != ']')
                    return false;
                else if( t== 0 )
                    return false;
                stk.pop();
            }
        }
        return stk.size()<=0;
    }
};
```
      