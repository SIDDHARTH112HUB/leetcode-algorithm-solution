[664.strange-printer](https://leetcode.com/problems/strange-printer/)  

There is a strange printer with the following two special requirements:

1.  The printer can only print a sequence of the same character each time.
2.  At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.

Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.

**Example 1:**  

  
**Input:** "aaabbb"
  
**Output:** 2
  
**Explanation:** Print "aaa" first and then print "bbb".
  

**Example 2:**  

  
**Input:** "aba"
  
**Output:** 2
  
**Explanation:** Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
  

**Hint**: Length of the given string will not exceed 100.  



**Solution:**  

```cpp
class Solution {
public:
    int strangePrinter(string s) {
        if(s.size() == 0 ) return 0;
        int dp[100][100] = {0};
        return helper(s, 0, s.size()-1, dp);
    }
    
    int helper(string &s, int i, int j, int dp[100][100]) {
        if(i > j) return 0;
        if(dp[i][j]) return dp[i][j];
        int res = 1 + helper(s, i + 1, j, dp);
        for(int k = i + 1; k <=j; k++) {
            if(s[k] == s[i])
                res = min(res, helper(s, i + 1, k-1, dp) + helper(s, k, j, dp));
        }
        dp[i][j] = res;
        return res;
    }
};
```
      