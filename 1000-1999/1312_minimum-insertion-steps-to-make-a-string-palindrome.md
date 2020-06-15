[1312.minimum-insertion-steps-to-make-a-string-palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)  

Given a string `s`. In one step you can insert any character at any index of the string.

Return _the minimum number of steps_ to make `s` palindrome.

A **Palindrome String** is one that reads the same backward as well as forward.

**Example 1:**

**Input:** s = "zzazz"
**Output:** 0
**Explanation:** The string "zzazz" is already palindrome we don't need any insertions.

**Example 2:**

**Input:** s = "mbadm"
**Output:** 2
**Explanation:** String can be "mbdadbm" or "mdbabdm".

**Example 3:**

**Input:** s = "leetcode"
**Output:** 5
**Explanation:** Inserting 5 characters the string becomes "leetcodocteel".

**Example 4:**

**Input:** s = "g"
**Output:** 0

**Example 5:**

**Input:** s = "no"
**Output:** 1

**Constraints:**

*   `1 <= s.length <= 500`
*   All characters of `s` are lower case English letters.  



**Solution:**  

```cpp
class Solution {
public:
    map<int, map<int, int> > m;
    int minInsertions(string s) {
        return helper(s, 0, s.size() - 1);
    }
    
    int helper(string &s, int l, int r) {
        if(r == l ) return 0;
        if( l > r) return 0;
        if(r - l == 1) return s[l] == s[r] ? 0 : 1;
        if(m[l].count(r)) return m[l][r];
        if(s[l] == s[r]) {
            return helper(s, l + 1, r - 1 );
        }
        int res = min(1 + helper(s, l + 1, r), 1 + helper(s, l, r-1));
        m[l][r] = res;
        return res;
    }
};
```
      