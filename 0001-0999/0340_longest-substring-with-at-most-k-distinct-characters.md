[340.longest-substring-with-at-most-k-distinct-characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)  

Given a string, find the length of the longest substring T that contains at most _k_ distinct characters.

**Example 1:**

**Input:** s = "eceba", k = 2
**Output:** 3
**Explanation:** T is "ece" which its length is 3.

**Example 2:**

**Input:** s = "aa", k = 1
**Output:** 2
**Explanation:** T is "aa" which its length is 2.  



**Solution:**  

```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0, j = 0, i = 0;
        unordered_map<int, int> cnt;
        for(; i < s.size(); ++i) {
            ++cnt[s[i]];
            if(cnt.size() > k) {
                ans = max(ans, i - j);
                while(cnt.size() > k) {
                    if(--cnt[s[j]] == 0)
                        cnt.erase(s[j]);
                    ++j;
                }
            }
        }
        return max(ans, i - j);
    }
};
```
      