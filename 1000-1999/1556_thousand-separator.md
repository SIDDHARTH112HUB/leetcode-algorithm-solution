[1556.thousand-separator](https://leetcode.com/problems/thousand-separator/)  

Given an integer `n`, add a dot (".") as the thousands separator and return it in string format.

**Example 1:**

  
**Input:** n = 987  
**Output:** "987"  

**Example 2:**

  
**Input:** n = 1234  
**Output:** "1.234"  

**Example 3:**

  
**Input:** n = 123456789  
**Output:** "123.456.789"  

**Example 4:**

  
**Input:** n = 0  
**Output:** "0"  

**Constraints:**

*   `0 <= n < 2^31`  



**Solution:**  

```cpp
class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        string ans;
        for(int i = 0; i < s.size(); ++i) {
            if(i % 3 == 0 && i > 0) ans+='.';
            ans +=s[i];
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      