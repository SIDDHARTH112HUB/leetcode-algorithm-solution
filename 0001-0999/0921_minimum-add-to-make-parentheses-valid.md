[921.minimum-add-to-make-parentheses-valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)  

Given a string `S` of `'('` and `')'` parentheses, we add the minimum number of parentheses ( `'('` or `')'`, and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

*   It is the empty string, or
*   It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
*   It can be written as `(A)`, where `A` is a valid string.

Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

**Example 1:**

  
**Input:** "())"
  
**Output:** 1
  

**Example 2:**

  
**Input:** "((("
  
**Output:** 3
  

**Example 3:**

  
**Input:** "()"
  
**Output:** 0
  

**Example 4:**

  
**Input:** "()))(("
  
**Output:** 4

**Note:**

1.  `S.length <= 1000`
2.  `S` only consists of `'('` and `')'` characters.  



**Solution:**  

```cpp
class Solution {
public:
    int minAddToMakeValid(string S) {
        int cnt = 0;
        int ans = 0;
        for( char c : S ){
            if( c == '(')
                cnt++;
            else
                cnt--;
            if( cnt < 0 ){
                ans++;
                cnt++;
            }
        }
        return ans + cnt;
    }
};
```
      