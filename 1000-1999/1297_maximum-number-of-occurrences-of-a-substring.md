[1297.maximum-number-of-occurrences-of-a-substring](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/)  

Given a string `s`, return the maximum number of ocurrences of **any** substring under the following rules:

*   The number of unique characters in the substring must be less than or equal to `maxLetters`.
*   The substring size must be between `minSize` and `maxSize` inclusive.

**Example 1:**

  
**Input:** s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
  
**Output:** 2
  
**Explanation:** Substring "aab" has 2 ocurrences in the original string.
  
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
  

**Example 2:**

  
**Input:** s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
  
**Output:** 2
  
**Explanation:** Substring "aaa" occur 2 times in the string. It can overlap.
  

**Example 3:**

  
**Input:** s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
  
**Output:** 3
  

**Example 4:**

  
**Input:** s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
  
**Output:** 0
  

**Constraints:**

*   `1 <= s.length <= 10^5`
*   `1 <= maxLetters <= 26`
*   `1 <= minSize <= maxSize <= min(26, s.length)`
*   `s` only contains lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        //int ans = 0;
        //map<int, int> m;
        map<string, int> ms;
        int b = 0, e = 0;
        for(int i = 0; i <= s.size() - minSize; ++i) {
            map<int, int> m;
            for(int k = 0; k < minSize; ++k) {
                ++m[s[k+i]];
            }
            if(m.size() > maxLetters) continue;
            ++ms[s.substr(i, minSize)];
        }
        string ans;
        int mx = 0;
        for(auto it : ms) {
            mx = max(mx, it.second);
        }
        return mx;
    }
};
```
      