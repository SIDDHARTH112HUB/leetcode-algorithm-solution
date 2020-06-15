[844.backspace-string-compare](https://leetcode.com/problems/backspace-string-compare/)  

Given two strings `S` and `T`, return if they are equal when both are typed into empty text editors. `#` means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

**Example 1:**

**Input:** S = "ab#c", T = "ad#c"
**Output:** true **Explanation**: Both S and T become "ac".

**Example 2:**

**Input:** S = "ab##", T = "c#d#"
**Output:** true **Explanation**: Both S and T become "".

**Example 3:**

**Input:** S = "a##c", T = "#a#c"
**Output:** true **Explanation**: Both S and T become "c".

**Example 4:**

**Input:** S = "a#c", T = "b"
**Output:** false **Explanation**: S becomes "c" while T becomes "b".

**Note**:

*   `1 <= S.length <= 200`
*   `1 <= T.length <= 200`
*   `S` and `T` only contain lowercase letters and `'#'` characters.

**Follow up:**

*   Can you solve it in `O(N)` time and `O(1)` space?  



**Solution:**  

```python3
class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        s = list(S);
        t = list(T);
        s.append(0)
        t.append(0)
        p = 0;
        string = s
        for idx, i in enumerate(string):
            if( i == '#'):
                if( p > 0):
                    p -= 1
                string[p] = 0; 
            else:
                string[p] = i
                p += 1;
        string = t;
        p = 0
        for idx, i in enumerate(string):
            if( i == '#'):
                if( p > 0):
                    p -= 1
                string[p] = 0; 
            else:
                string[p] = i
                p += 1;
        
        l = min(len(s), len(t))
        for i in range(l):
            if( s[i] != t[i]):
                return False;
            if( s[i] == t[i] and t[i] == 0 ):
                return True
        return False
```
      