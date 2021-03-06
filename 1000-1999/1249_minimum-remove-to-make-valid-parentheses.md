[1249.minimum-remove-to-make-valid-parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)  

Given a string s of `'('` , `')'` and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting _parentheses string_ is valid and return **any** valid string.

Formally, a _parentheses string_ is valid if and only if:

*   It is the empty string, contains only lowercase characters, or
*   It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
*   It can be written as `(A)`, where `A` is a valid string.

**Example 1:**

  
**Input:** s = "lee(t(c)o)de)"
  
**Output:** "lee(t(c)o)de"
  
**Explanation:** "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
  

**Example 2:**

  
**Input:** s = "a)b(c)d"
  
**Output:** "ab(c)d"
  

**Example 3:**

  
**Input:** s = "))(("
  
**Output:** ""
  
**Explanation:** An empty string is also valid.
  

**Example 4:**

  
**Input:** s = "(a(b(c)d)"
  
**Output:** "a(b(c)d)"
  

**Constraints:**

*   `1 <= s.length <= 10^5`
*   `s[i]` is one of  `'('` , `')'` and lowercase English letters`.`  



**Solution:**  

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<int, int> > stk;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] >= 'a' && s[i] <= 'z') continue;
            if(s[i] == '(' || stk.size() == 0) {
                stk.push_back({s[i], i});
            }else {
                if(stk.back().first == '(') {
                    stk.pop_back();
                }else {
                    stk.push_back({s[i], i});
                }
            }
        }
        int j = 0;
        string ans;
        for(int i = 0; i < s.size(); ++i) {
            if(j < stk.size() && stk[j].second == i) {
                ++j;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};
```
      