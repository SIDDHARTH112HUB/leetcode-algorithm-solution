[32.longest-valid-parentheses](https://leetcode.com/problems/longest-valid-parentheses/)  

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**

  
**Input:** "(()"
  
**Output:** 2
  
**Explanation:** The longest valid parentheses substring is `"()"`
  

**Example 2:**

  
**Input:** "`)()())`"
  
**Output:** 4
  
**Explanation:** The longest valid parentheses substring is `"()()"`  



**Solution:**  

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack< pair<int, int> > stk;
        stk.push({-1, -1});
        int ans = 0;
        for(int i = 0; i<s.size(); i++ ){
            char c = s[i];
            if( c == '('){
                stk.push({1, i} );
            }else{
                if( stk.size() > 0 && stk.top().first >= 0 ){
                    stk.pop();
                    ans = max( ans, i - stk.top().second);
                }else{
                    stk.push({-1, i});
                }
            }
        }
        return ans;
    }
};
```
      