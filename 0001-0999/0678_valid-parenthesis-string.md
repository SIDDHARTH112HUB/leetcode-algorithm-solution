[678.valid-parenthesis-string](https://leetcode.com/problems/valid-parenthesis-string/)  

Given a string containing only three types of characters: '(', ')' and '\*', write a function to check whether this string is valid. We define the validity of a string by these rules:

1.  Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2.  Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3.  Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4.  `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string.
5.  An empty string is also valid.

**Example 1:**  

  
**Input:** "()"
  
**Output:** True
  

**Example 2:**  

  
**Input:** "(\*)"
  
**Output:** True
  

**Example 3:**  

  
**Input:** "(\*))"
  
**Output:** True
  

**Note:**  

1.  The string size will be in the range \[1, 100\].  



**Solution:**  

```python
class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        star = []
        p = []
        c=0
        for i in s:
            c+=1;
            if i == "(":
                p.append( (c, i))
            elif i == ")":
                if len(p):
                    p.pop()
                elif len(star):
                    star.pop()
                else:
                    return False
            else:
                star.append((c,i));
        lp = len(p)
        ls = len(star)
        if lp > ls:
            return False;
        p.sort(reverse=True)
        star.sort(reverse=True)
        #print(p, star)
        for idx, pitem in enumerate( p ):
            if pitem[0] > star[idx][0]:
                return False;
        return True
```
      