[291.word-pattern-ii](https://leetcode.com/problems/word-pattern-ii/)  

Given a `pattern` and a string `str`, find if `str` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** substring in `str`.

**Example 1:**

**Input:** pattern = "abab", str = "redblueredblue"  
**Output:** true  

**Example 2:**

**Input:** pattern = "aaaa", str = "asdasdasdasd"  
**Output:** true  

**Example 3:**

**Input:** pattern = "aabb", str = "xyzabcxzyabc"  
**Output:** false  

**Constraints:**

*   You may assume both `pattern` and `str` contains only lowercase letters.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<char, string> m1;
    unordered_map<string, char> m2;
    bool wordPatternMatch(string pattern, string str) {
        return dfs(pattern, 0, str);
    }
    
    bool dfs(string &pattern, int idx, string str) {
        if(str.size() < pattern.size() - idx) return false;
        if(idx >= pattern.size()) return str.size() == 0;
        int p = pattern[idx];
        auto ps = m1[p];
        if(ps.size() == 0) {
            for(int i = 1; i <= str.size(); ++i) {
                auto ns = str.substr(0, i);
                if(m2.count(ns)) continue;
                m1[p] = ns;
                m2[ns] = p;
                if(dfs(pattern, idx+1, str.substr(i)))
                    return true;
                m2.erase(ns);
                m1.erase(p);
            }
        }else {
            if(p != m2[ps]) return false;
            if(str.substr(0, ps.size()) != ps) return false;
            if(dfs(pattern, idx + 1, str.substr(ps.size())))
                return true;
        }
        return false;
    }
};
```
      