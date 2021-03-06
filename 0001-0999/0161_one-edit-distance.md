[161.one-edit-distance](https://leetcode.com/problems/one-edit-distance/)  

Given two strings **_s_** and **_t_**, determine if they are both one edit distance apart.

**Note:** 

There are 3 possiblities to satisify one edit distance apart:

1.  Insert a character into **_s_** to get **_t_**
2.  Delete a character from **_s_** to get **_t_**
3.  Replace a character of **_s_** to get **_t_**

**Example 1:**

  
**Input:** **_s_** = "ab", **_t_** = "acb"
  
**Output:** true
  
**Explanation:** We can insert 'c' into **_s_** to get **_t._**
  

**Example 2:**

  
**Input:** **_s_** = "cab", **_t_** = "ad"
  
**Output:** false
  
**Explanation:** We cannot get **_t_** from **_s_** by only one step.

**Example 3:**

  
**Input:** **_s_** = "1203", **_t_** = "1213"
  
**Output:** true
  
**Explanation:** We can replace '0' with '1' to get **_t._**  



**Solution:**  

```cpp
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(abs((int)s.size() - (int)t.size()) > 1) return false;
        if(s == t) return false;
        for(int i = 0; i < min(s.size(), t.size()); ++i) {
            if(s[i] != t[i]) {
                if(s.size() == t.size())
                    return s.substr(i + 1) == t.substr(i + 1);
                int sl = s.size() > t.size();
                return s.substr(i + sl) == t.substr(i + !sl);
            }
        }
        return true;
    }
};
```
      