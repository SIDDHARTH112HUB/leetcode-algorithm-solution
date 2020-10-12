[1573.number-of-ways-to-split-a-string](https://leetcode.com/problems/number-of-ways-to-split-a-string/)  

Given a binary string `s` (a string consisting only of '0's and '1's), we can split `s` into 3 **non-empty** strings s1, s2, s3 (s1+ s2+ s3 = s).

Return the number of ways `s` can be split such that the number of characters '1' is the same in s1, s2, and s3.

Since the answer may be too large, return it modulo 10^9 + 7.

**Example 1:**

  
**Input:** s = "10101"  
**Output:** 4  
**Explanation:** There are four ways to split s in 3 parts where each part contain the same number of letters '1'.  
"1|010|1"  
"1|01|01"  
"10|10|1"  
"10|1|01"  

**Example 2:**

  
**Input:** s = "1001"  
**Output:** 0  

**Example 3:**

  
**Input:** s = "0000"  
**Output:** 3  
**Explanation:** There are three ways to split s in 3 parts.  
"0|0|00"  
"0|00|0"  
"00|0|0"  

**Example 4:**

  
**Input:** s = "100100010100110"  
**Output:** 12  

**Constraints:**

*   `3 <= s.length <= 10^5`
*   `s[i]` is `'0'` or `'1'`.  



**Solution:**  

```cpp
class Solution {
public:
    int numWays(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c == '1') ++cnt;
        }
        if(cnt % 3) return 0;
        long long M = 1e9 + 7;
        long long ans = 0;
        if(cnt == 0) {
            for(int i = s.size() - 2; i >= 1; --i)
                (ans += i)%=M;
            return ans;
        }
        long long cur = 0;
        long long l = 0, r = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(c == '1') ++cur;
            if(cur == cnt / 3) {
                ++l;
            }
            if(cur == 2 * cnt / 3) {
                ++r;
            }
        }
        return (l * r) % M;
    }
};
```
      