[395.longest-substring-with-at-least-k-repeating-characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)  

Find the length of the longest substring **_T_** of a given string (consists of lowercase letters only) such that every character in **_T_** appears no less than _k_ times.

**Example 1:**

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.

**Example 2:**

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.  



**Solution:**  

```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        if( s.size() < k ) return 0;
        int mxIdx = 0, n = s.size(), res = 0;
        int cnt[128] = {0};
        for(auto c : s)
            ++cnt[c];
        bool ok = true;
        for(int i = 0; i < s.size(); ++i) {
            if(cnt[s[i]] < k) {
                res = max(res, longestSubstring(s.substr(mxIdx, i - mxIdx), k));
                ok = false;
                mxIdx = i + 1;
            }
        }
        return ok ? n : max(res, longestSubstring(s.substr(mxIdx, n - mxIdx), k));
    }
};
```
      