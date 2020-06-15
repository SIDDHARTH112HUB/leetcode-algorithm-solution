[1358.number-of-substrings-containing-all-three-characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)  

Given a string `s` consisting only of characters _a_, _b_ and _c_.

Return the number of substrings containing **at least** one occurrence of all these characters _a_, _b_ and _c_.

**Example 1:**

**Input:** s = "abcabc"
**Output:** 10
**Explanation:** The substrings containing at least one occurrence of the characters _a_, _b_ and _c are "_abc_", "_abca_", "_abcab_", "_abcabc_", "_bca_", "_bcab_", "_bcabc_", "_cab_", "_cabc_"_ and _"_abc_"_ (**again**)_._ 

**Example 2:**

**Input:** s = "aaacb"
**Output:** 3
**Explanation:** The substrings containing at least one occurrence of the characters _a_, _b_ and _c are "_aaacb_", "_aacb_"_ and _"_acb_"._ 

**Example 3:**

**Input:** s = "abc"
**Output:** 1

**Constraints:**

*   `3 <= s.length <= 5 x 10^4`
*   `s` only consists of _a_, _b_ or _c_ characters.  



**Solution:**  

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, st = 0, e = 0, go = 0;
        vector<int> cnt(3);
        while(e < s.size()) {
            if(cnt[s[e++] - 'a']++ == 0) go++;
            int prev = st;
            while(go >= 3 ) {
                if(cnt[s[st++] - 'a']-- == 1) --go;
            }
            ans += (st - prev) * (s.size() - e+ 1);
        }
        return ans;
    }
};
```
      