[242.valid-anagram](https://leetcode.com/problems/valid-anagram/)  

Given two strings _s_ and _t_ , write a function to determine if _t_ is an anagram of _s_.

**Example 1:**

**Input:** _s_ = "anagram", _t_ = "nagaram"
**Output:** true

**Example 2:**

**Input:** _s_ = "rat", _t_ = "car"
**Output:** false

**Note:**  
You may assume the string contains only lowercase alphabets.

**Follow up:**  
What if the inputs contain unicode characters? How would you adapt your solution to such case?  



**Solution:**  

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() ) return false;
        int hash[128] = {0};
        for( char c : s)
            ++hash[c];
        for( char c:t)
            if( hash[c]-- == 0 )
                return false;
        return true;
    }
};
```
      