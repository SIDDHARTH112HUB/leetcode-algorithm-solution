[1153.string-transforms-into-another-string](https://leetcode.com/problems/string-transforms-into-another-string/)  

Given two strings `str1` and `str2` of the same length, determine whether you can transform `str1` into `str2` by doing **zero or more** _conversions_.

In one conversion you can convert **all** occurrences of one character in `str1` to **any** other lowercase English character.

Return `true` if and only if you can transform `str1` into `str2`.

**Example 1:**

  
**Input:** str1 = "aabcc", str2 = "ccdee"  
**Output:** true  
**Explanation:** Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.  

**Example 2:**

  
**Input:** str1 = "leetcode", str2 = "codeleet"  
**Output:** false  
**Explanation:** There is no way to transform str1 to str2.  

**Note:**

1.  `1 <= str1.length == str2.length <= 10^4`
2.  Both `str1` and `str2` contain only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        unordered_map<int, int> m, m2;
        for(int i = 0; i < str1.size(); ++i) {
            int a = str1[i], b = str2[i];
            if(m.count(a) && m[a] != b)
                return false;
            m[a] = b;
            m2[b] = a;
        }
        return m2.size() < 26;
    }
};
```
      