[1071.greatest-common-divisor-of-strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)  

For strings `S` and `T`, we say "`T` divides `S`" if and only if `S = T + ... + T`  (`T` concatenated with itself 1 or more times)

Return the largest string `X` such that `X` divides str1 and `X` divides str2.

**Example 1:**

  
**Input:** str1 = "ABCABC", str2 = "ABC"  
**Output:** "ABC"  

**Example 2:**

  
**Input:** str1 = "ABABAB", str2 = "ABAB"  
**Output:** "AB"  

**Example 3:**

  
**Input:** str1 = "LEET", str2 = "CODE"  
**Output:** ""  

**Note:**

1.  `1 <= str1.length <= 1000`
2.  `1 <= str2.length <= 1000`
3.  `str1[i]` and `str2[i]` are English uppercase letters.  



**Solution:**  

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if(str1 == str2) return str1;
        if(str1.substr(0, str2.size()) != str2) return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};
```
      