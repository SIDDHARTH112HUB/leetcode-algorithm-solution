[1062.longest-repeating-substring](https://leetcode.com/problems/longest-repeating-substring/)  

Given a string `S`, find out the length of the longest repeating substring(s). Return `0` if no repeating substring exists.

**Example 1:**

  
**Input:** "abcd"
  
**Output:** 0
  
**Explanation:** There is no repeating substring.
  

**Example 2:**

  
**Input:** "abbaba"
  
**Output:** 2
  
**Explanation:** The longest repeating substrings are "ab" and "ba", each of which occurs twice.
  

**Example 3:**

  
**Input:** "aabcaabdaab"
  
**Output:** 3
  
**Explanation:** The longest repeating substring is "aab", which occurs `3` times.
  

**Example 4:**

  
**Input:** "aaaaa"
  
**Output:** 4
  
**Explanation:** The longest repeating substring is "aaaa", which occurs twice.
  

**Note:**

1.  The string `S` consists of only lowercase English letters from `'a'` - `'z'`.
2.  `1 <= S.length <= 1500`  



**Solution:**  

```cpp
class Solution {
public:
    
    int longestRepeatingSubstring(string S) {
        int ans = 0;
        for(int i = 0; i < S.size(); ++i) {
            ans = max(ans, kmp(S, i));
        }
        return ans;
    }
    
    int kmp(string &s, int start) {
        int j = start;
        vector<int> p(s.size());
        int res = 0;
        for(int i = start + 1; i < s.size(); ++i) {
            while(j > start && s[j] != s[i]) j = p[j - 1] + start;
            if(s[j] == s[i]) p[i] = (++j) - start;
            res = max(res, j - start);
        }
        return res;
    }
};
```
      