[1585.check-if-string-is-transformable-with-substring-sort-operations](https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/)  

Given two strings `s` and `t`, you want to transform string `s` into string `t` using the following operation any number of times:

*   Choose a **non-empty** substring in `s` and sort it in-place so the characters are in **ascending order**.

For example, applying the operation on the underlined substring in `"14234"` results in `"12344"`.

Return `true` if _it is possible to transform string `s` into string `t`_. Otherwise, return `false`.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

  
**Input:** s = "84532", t = "34852"  
**Output:** true  
**Explanation:** You can transform s into t using the following sort operations:  
"84532" (from index 2 to 3) -> "84352"  
"84352" (from index 0 to 2) -> "34852"  

**Example 2:**

  
**Input:** s = "34521", t = "23415"  
**Output:** true  
**Explanation:** You can transform s into t using the following sort operations:  
"34521" -> "23451"  
"23451" -> "23415"  

**Example 3:**

  
**Input:** s = "12345", t = "12435"  
**Output:** false  

**Example 4:**

  
**Input:** s = "1", t = "2"  
**Output:** false  

**Constraints:**

*   `s.length == t.length`
*   `1 <= s.length <= 105`
*   `s` and `t` only contain digits from `'0'` to `'9'`.  



**Solution:**  

```cpp
class Solution {
public:
    bool isTransformable(string s, string t) {
        for(int c = '9'; c >= '0'; --c) {
            vector<int> a, b;
            string ns, nt;
            for(int i = 0; i < s.size(); ++i) {
                if(s[i] == c) a.push_back(i);
                if(t[i] == c) b.push_back(i);
                if(s[i] < c) ns += s[i];
                if(t[i] < c) nt += t[i];
            }
            if(a.size() != b.size()) return false;
            for(int i = 0; i < a.size(); ++i)
                if(a[i] > b[i]) return false;
            s = ns; t = nt;
        }
        return true;
    }
};

```
      