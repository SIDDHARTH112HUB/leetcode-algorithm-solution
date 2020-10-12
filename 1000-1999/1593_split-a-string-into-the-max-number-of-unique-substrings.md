[1593.split-a-string-into-the-max-number-of-unique-substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/)  

Given a string `s`, return _the maximum number of unique substrings that the given string can be split into_.

You can split string `s` into any list of **non-empty substrings**, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are **unique**.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

  
**Input:** s = "ababccc"  
**Output:** 5  
**Explanation**: One way to split maximally is \['a', 'b', 'ab', 'c', 'cc'\]. Splitting like \['a', 'b', 'a', 'b', 'c', 'cc'\] is not valid as you have 'a' and 'b' multiple times.  

**Example 2:**

  
**Input:** s = "aba"  
**Output:** 2  
**Explanation**: One way to split maximally is \['a', 'ba'\].  

**Example 3:**

  
**Input:** s = "aa"  
**Output:** 1  
**Explanation**: It is impossible to split the string any further.  

**Constraints:**

*   `1 <= s.length <= 16`
    
*   `s` contains only lower case English letters.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_set<string> m;
    int ans = 0;
    void dfs(string &s, int idx) {
        if(idx >= s.size()) {
            ans = max(ans, (int)m.size());
            return;
        }
        for(int i = idx; i < s.size(); ++i) {
            string ns = s.substr(idx, i - idx + 1);
            if(m.count(ns)) continue;
            m.insert(ns);
            dfs(s, i + 1);
            m.erase(ns);
        }
    }
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return ans;
    }
};
```
      