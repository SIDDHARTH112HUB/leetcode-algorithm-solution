[1119.remove-vowels-from-a-string](https://leetcode.com/problems/remove-vowels-from-a-string/)  

Given a string `S`, remove the vowels `'a'`, `'e'`, `'i'`, `'o'`, and `'u'` from it, and return the new string.

**Example 1:**

  
**Input:** "leetcodeisacommunityforcoders"
  
**Output:** "ltcdscmmntyfrcdrs"
  

**Example 2:**

  
**Input:** "aeiou"
  
**Output:** ""
  

**Note:**

1.  `S` consists of lowercase English letters only.
2.  `1 <= S.length <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    string removeVowels(string S) {
        string ans;
        
        for(auto c : S){
            if(c != 'a' && c != 'e'&& c !='i' && c != 'o' && c != 'u')
                ans += c;
        }
        return ans;
    }
};
```
      