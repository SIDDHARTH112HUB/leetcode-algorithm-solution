[1163.last-substring-in-lexicographical-order](https://leetcode.com/problems/last-substring-in-lexicographical-order/)  

Given a string `s`, return the last substring of `s` in lexicographical order.

**Example 1:**

  
**Input:** "abab"  
**Output:** "bab"  
**Explanation:** The substrings are \["a", "ab", "aba", "abab", "b", "ba", "bab"\]. The lexicographically maximum substring is "bab".  

**Example 2:**

  
**Input:** "leetcode"  
**Output:** "tcode"  

**Note:**

1.  `1 <= s.length <= 4 * 10^5`
2.  s contains only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    string lastSubstring(string s) {
        int mc = 0;
        for(int c : s)
            mc = max(c, mc);
        int prev = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == mc) {
                int idx = i;
                while(i + 1 < s.size() && s[i+1] == s[i])
                    ++i;
                if(prev == -1){
                    prev = idx;
                    continue;
                }
                for(int k = 0; k < s.size() - idx; ++k){
                    if(s[prev+k] > s[idx + k]){
                        break;
                    }
                    else if(s[prev+k] < s[idx + k]){
                        prev = idx;
                        break;
                    }
                }
            }
        }
        return s.substr(prev);
    }
};
```
      