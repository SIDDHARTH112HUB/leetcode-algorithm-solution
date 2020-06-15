[541.reverse-string-ii](https://leetcode.com/problems/reverse-string-ii/)  

Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.

**Example:**  

**Input:** s = "abcdefg", k = 2
**Output:** "bacdfeg"

**Restrictions:**

1.  The string consists of lower English letters only.
2.  Length of the given string and k will in the range \[1, 10000\]  



**Solution:**  

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, s.begin() + i + k > s.end()?s.end() : s.begin() + i +k);
        }
        return s;
    }
};
```
      