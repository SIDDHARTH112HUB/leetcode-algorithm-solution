[1216.valid-palindrome-iii](https://leetcode.com/problems/valid-palindrome-iii/)  

Given a string `s` and an integer `k`, find out if the given string is a _K-Palindrome_ or not.

A string is K-Palindrome if it can be transformed into a palindrome by removing at most `k` characters from it.

**Example 1:**

  
**Input:** s = "abcdeca", k = 2  
**Output:** true  
**Explanation:** Remove 'b' and 'e' characters.  

**Constraints:**

*   `1 <= s.length <= 1000`
*   `s` has only lowercase English letters.
*   `1 <= k <= s.length`  



**Solution:**  

```cpp
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int dp[s.size() + 1][s.size() + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
            for(int j = i-1; j >=0; --j){
                if(s[i] == s[j]){
                    dp[j][i] = dp[j+1][i-1] + 2;
                }else{
                    dp[j][i] = max(dp[j][i-1], dp[j+1][i]);
                }
            }
        }
        return s.size() <= dp[0][s.size()-1] +k;
    }
};
```
      