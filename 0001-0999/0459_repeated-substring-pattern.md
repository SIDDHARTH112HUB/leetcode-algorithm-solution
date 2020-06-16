[459.repeated-substring-pattern](https://leetcode.com/problems/repeated-substring-pattern/)  

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

**Example 1:**

  
**Input:** "abab"
  
**Output:** True
  
**Explanation:** It's the substring "ab" twice.
  

**Example 2:**

  
**Input:** "aba"
  
**Output:** False
  

**Example 3:**

  
**Input:** "abcabcabcabc"
  
**Output:** True
  
**Explanation:** It's the substring "abc" four times. (And the substring "abcabc" twice.)  



**Solution:**  

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i <= s.size()/2; ++i) {
            if(s.size() % i) continue;
            bool f = true;
            for(int j = i; j < s.size(); ++j) {
                if(s[j] != s[j % i]) {
                    f = false;
                    break;
                }
            }
            if(f) return true;
        }
        return false;
    }
};
```
      