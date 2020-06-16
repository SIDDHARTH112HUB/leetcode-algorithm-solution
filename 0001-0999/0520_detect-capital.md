[520.detect-capital](https://leetcode.com/problems/detect-capital/)  

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

1.  All letters in this word are capitals, like "USA".
2.  All letters in this word are not capitals, like "leetcode".
3.  Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

**Example 1:**

  
**Input:** "USA"
  
**Output:** True
  

**Example 2:**

  
**Input:** "FlaG"
  
**Output:** False
  

**Note:** The input will be a non-empty word consisting of uppercase and lowercase latin letters.  



**Solution:**  

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1) return true;
        bool l = false, u = false;
        for(int i = 1; i < word.size(); ++i) {
            char c = word[i];
            if(c >='a' && c<='z') {
                l = true;
            }else
                u = true;
        }
        if(word[0] >= 'A' && word[0]<='Z') return !(l && u);
        return l && !u;
    }
};
```
      