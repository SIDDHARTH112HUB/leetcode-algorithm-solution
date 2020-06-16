[205.isomorphic-strings](https://leetcode.com/problems/isomorphic-strings/)  

Given two strings **_s_** and **_t_**, determine if they are isomorphic.

Two strings are isomorphic if the characters in **_s_** can be replaced to get **_t_**.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

**Example 1:**

  
**Input:** **_s_** = `"egg",` **_t =_** `"add"`
  
**Output:** true
  

**Example 2:**

  
**Input:** **_s_** = `"foo",` **_t =_** `"bar"`
  
**Output:** false

**Example 3:**

  
**Input:** **_s_** = `"paper",` **_t =_** `"title"`
  
**Output:** true

**Note:**  
You may assume both **_s_** and **_t_** have the same length.  



**Solution:**  

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int, int> m1, m2;
        for(int i = 0; i<s.size(); i++){
            if( m1[s[i]] == 0 && m2[t[i]] == 0 ){
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if( m1[s[i]] != t[i] )
                return false;
            else if( m2[t[i]] != s[i] )
                return false;
        }
        return true;
    }
};
```
      