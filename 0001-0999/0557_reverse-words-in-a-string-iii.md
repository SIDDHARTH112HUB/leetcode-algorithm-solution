[557.reverse-words-in-a-string-iii](https://leetcode.com/problems/reverse-words-in-a-string-iii/)  

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

**Example 1:**  

  
**Input:** "Let's take LeetCode contest"
  
**Output:** "s'teL ekat edoCteeL tsetnoc"
  

**Note:** In the string, each word is separated by single space and there will not be any extra space in the string.  



**Solution:**  

```cpp
class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0, j = 0; i <= s.size(); ++i) {
            if(i < s.size() && s[i] !=' ') continue;
            reverse(s.begin() + j, s.begin() + i);
            j = i + 1;
        }
        return s;
    }
};
```
      