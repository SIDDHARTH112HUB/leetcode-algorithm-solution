[1143.longest-common-subsequence](https://leetcode.com/problems/longest-common-subsequence/)  

Given two strings `text1` and `text2`, return the length of their longest common subsequence.

A _subsequence_ of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A _common subsequence_ of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

**Example 1:**

  
**Input:** text1 = "abcde", text2 = "ace"   
**Output:** 3    
**Explanation:** The longest common subsequence is "ace" and its length is 3.  

**Example 2:**

  
**Input:** text1 = "abc", text2 = "abc"  
**Output:** 3  
**Explanation:** The longest common subsequence is "abc" and its length is 3.  

**Example 3:**

  
**Input:** text1 = "abc", text2 = "def"  
**Output:** 0  
**Explanation:** There is no such common subsequence, so the result is 0.  

**Constraints:**

*   `1 <= text1.length <= 1000`
*   `1 <= text2.length <= 1000`
*   The input strings consist of lowercase English characters only.  



**Solution:**  

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text2.size()+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= text1.size(); ++i){
            int prev = 0;
            for(int j = 1; j <= text2.size(); ++j) {
                int a = text1[i-1];
                int b = text2[j-1];
                int t = dp[j];
                if (a == b) {
                    dp[j] = prev + 1;
                }else{
                    dp[j] = max(dp[j-1], dp[j]);
                }
                prev = t;
            }
        }
        return dp[text2.size()];
    }
};
```
      