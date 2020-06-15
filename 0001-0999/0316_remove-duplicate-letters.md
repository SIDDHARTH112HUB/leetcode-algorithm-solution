[316.remove-duplicate-letters](https://leetcode.com/problems/remove-duplicate-letters/)  

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

**Example 1:**

**Input:** `"bcabc"`
**Output:** `"abc"`

**Example 2:**

**Input:** `"cbacdcbc"`
**Output:** `"acdb"`

**Note:** This question is the same as 1081: [https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)  



**Solution:**  

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<int, int> m;
        unordered_set<int> v;
        for(auto c : s)
            ++m[c];
        string ans;
        for(auto c : s) {
            --m[c];
            if(v.count(c)) continue;
            while(ans.size() && ans.back() > c && m[ans.back()] > 0) {
                v.erase(ans.back());
                ans.pop_back();
            }
            ans += c;
            v.insert(c);
        }
        return ans;
    }
};
```
      