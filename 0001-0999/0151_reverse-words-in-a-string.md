[151.reverse-words-in-a-string](https://leetcode.com/problems/reverse-words-in-a-string/)  

Given an input string, reverse the string word by word.

**Example 1:**

  
**Input:** "`the sky is blue`"
  
**Output:** "`blue is sky the`"
  

**Example 2:**

  
**Input:** "  hello world!  "
  
**Output:** "world! hello"
  
**Explanation:** Your reversed string should not contain leading or trailing spaces.
  

**Example 3:**

  
**Input:** "a good   example"
  
**Output:** "example good a"
  
**Explanation:** You need to reduce multiple spaces between two words to a single space in the reversed string.
  

**Note:**

*   A word is defined as a sequence of non-space characters.
*   Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
*   You need to reduce multiple spaces between two words to a single space in the reversed string.

**Follow up:**

For C programmers, try to solve it _in-place_ in _O_(1) extra space.  



**Solution:**  

```python
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s=s.strip()
        if s=="": return ""
        l = s.split()
        l.reverse()
        return " ".join(l)
        
```
      