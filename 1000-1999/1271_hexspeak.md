[1271.hexspeak](https://leetcode.com/problems/hexspeak/)  

A decimal number can be converted to its _Hexspeak representation_ by first converting it to an uppercase hexadecimal string, then replacing all occurrences of the digit `0` with the letter `O`, and the digit `1` with the letter `I`.  Such a representation is _valid_ if and only if it consists only of the letters in the set `{"A", "B", "C", "D", "E", "F", "I", "O"}`.

Given a string `num` representing a decimal integer `N`, return the Hexspeak representation of `N` if it is valid, otherwise return `"ERROR"`.

**Example 1:**

  
**Input:** num = "257"  
**Output:** "IOI"  
**Explanation: ** 257 is 101 in hexadecimal.  

**Example 2:**

  
**Input:** num = "3"  
**Output:** "ERROR"  

**Constraints:**

*   `1 <= N <= 10^12`
*   There are no leading zeros in the given string.
*   All answers must be in uppercase letters.  



**Solution:**  

```cpp
class Solution {
public:
    string toHexspeak(string num) {
        long long n = stoll(num);
        string ans;
        while(n > 0) {
            int mod = n % 16;
            if(mod >= 2 && mod <=9) return "ERROR";
            if(mod == 0) {
                ans += 'O';
            }else if(mod == 1)
                ans += 'I';
            else
                ans += mod - 10 + 'A';
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      