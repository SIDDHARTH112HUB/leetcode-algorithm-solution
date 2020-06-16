[1328.break-a-palindrome](https://leetcode.com/problems/break-a-palindrome/)  

Given a palindromic string `palindrome`, replace **exactly one** character by any lowercase English letter so that the string becomes the lexicographically smallest possible string that **isn't** a palindrome.

After doing so, return the final string.  If there is no way to do so, return the empty string.

**Example 1:**

  
**Input:** palindrome = "abccba"
  
**Output:** "aaccba"
  

**Example 2:**

  
**Input:** palindrome = "a"
  
**Output:** ""
  

**Constraints:**

*   `1 <= palindrome.length <= 1000`
*   `palindrome` consists of only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size() <= 1) return "";
        for(int i = 0; i < p.size() / 2; ++i) {
            if(p[i] != 'a'){
                p[i] = 'a';
                return p;
            }
        }
        p[p.size() - 1] = 'b';
        return p;
    }
};
```
      