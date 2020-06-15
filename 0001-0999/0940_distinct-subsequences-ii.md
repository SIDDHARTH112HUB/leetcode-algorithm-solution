[940.distinct-subsequences-ii](https://leetcode.com/problems/distinct-subsequences-ii/)  

Given a string `S`, count the number of distinct, non-empty subsequences of `S` .

Since the result may be large, **return the answer modulo `10^9 + 7`**.

**Example 1:**

**Input:** "abc"
**Output:** 7
**Explanation**: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

**Example 2:**

**Input:** "aba"
**Output:** 6 **Explanation**: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".

**Example 3:**

**Input:** "aaa"
**Output:** 3 **Explanation**: The 3 distinct subsequences are "a", "aa" and "aaa".

**Note:**

1.  `S` contains only lowercase letters.
2.  `1 <= S.length <= 2000`  



**Solution:**  

```cpp
class Solution {
public:
    int distinctSubseqII(string S) {
        int dp[S.size()+1] = {0};
        dp[0] = 1;
        int last[256];
        int M = 1000000007;
        for( int i = 0; i<256;i++)
            last[i] = -1;
        for( int i = 1; i<=S.size(); i++ ){
            dp[i] = (2 * dp[i-1] )% M;
            char c = S[i-1];
            if( last[c] != -1 )
                dp[i] = ((dp[i] + M) - dp[last[c]])%M;
            last[c] = i-1;
        }
        return dp[S.size()]-1;
    }
};
```
      