[1016.binary-string-with-substrings-representing-1-to-n](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/)  

Given a binary string `S` (a string consisting only of '0' and '1's) and a positive integer `N`, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.

**Example 1:**

**Input:** S = "0110", N = 3
**Output:** true

**Example 2:**

**Input:** S = "0110", N = 4
**Output:** false

**Note:**

1.  `1 <= S.length <= 1000`
2.  `1 <= N <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    string bin(int n) {
        string ans;
        while(n > 0){
            ans += (n & 1)? '1' : '0';
            n >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool queryString(string S, int N) {
        
        for(int i = N; i >= 1; --i) {
            if(S.find(bin(i)) == S.npos) return false;
        }
        return true;
    }
};
```
      