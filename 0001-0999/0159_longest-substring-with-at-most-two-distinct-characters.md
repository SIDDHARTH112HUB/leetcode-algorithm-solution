[159.longest-substring-with-at-most-two-distinct-characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)  

Given a string **_s_** , find the length of the longest substring **_t_** that contains **at most** 2 distinct characters.

**Example 1:**

**Input:** "eceba"
**Output:** 3
**Explanation: _t_** is "ece" which its length is 3.

**Example 2:**

**Input:** "ccaabbb"
**Output:** 5
**Explanation: _t_** is "aabbb" which its length is 5.  



**Solution:**  

```cpp
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int j = 0, i = 0, ans = 0;
        map<int, int> m;
        for(; i < s.size(); ++i) {
            ++m[s[i]];
            if(m.size() > 2) {
                ans = max(ans, i - j);
                while(j < i && m.size() >2) {
                    --m[s[j]];
                    if(m[s[j]] == 0)
                        m.erase(s[j]);
                    ++j;
                }
            }
        }
        ans = max(ans, i - j);
        return ans;
    }
};
```
      