[394.decode-string](https://leetcode.com/problems/decode-string/)  

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the _encoded\_string_ inside the square brackets is being repeated exactly _k_ times. Note that _k_ is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, _k_. For example, there won't be input like `3a` or `2[4]`.

**Example 1:**

**Input:** s = "3\[a\]2\[bc\]"
**Output:** "aaabcbc"

**Example 2:**

**Input:** s = "3\[a2\[c\]\]"
**Output:** "accaccacc"

**Example 3:**

**Input:** s = "2\[abc\]3\[cd\]ef"
**Output:** "abcabccdcdcdef"

**Example 4:**

**Input:** s = "abc3\[cd\]xyz"
**Output:** "abccdcdcdxyz"  



**Solution:**  

```cpp
class Solution {
public:
    int idx = 0;
    string decodeString(string s) {
        string ans;
        int num = 0;
        while(idx < s.size()) {
            char c = s[idx];
            if(c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }else if(c == '['){
                ++idx;
                auto str = decodeString(s);
                while(num > 0){
                    --num;
                    ans += str;
                }
            }else if(c == ']'){
                return ans;
            }else {
                ans += c;
            }
            ++idx;
        }
        return ans;
    }
};
```
      