[583.delete-operation-for-two-strings](https://leetcode.com/problems/delete-operation-for-two-strings/)  

Given two words _word1_ and _word2_, find the minimum number of steps required to make _word1_ and _word2_ the same, where in each step you can delete one character in either string.

**Example 1:**  

**Input:** "sea", "eat"
**Output:** 2
**Explanation:** You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

**Note:**  

1.  The length of given words won't exceed 500.
2.  Characters in given words can only be lower-case letters.  



**Solution:**  

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word2.size()+1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for( int i = 1;  i <= word1.size(); i++ ){
            int prev = 0;
            for( int j = 1; j<=word2.size(); j++){
                int tmp = dp[j];
                if( word1[i-1] == word2[j-1] ){
                    dp[j] = prev+1;
                }else{
                    dp[j] = max(dp[j], dp[j-1]); 
                }
                prev = tmp;
            }
        }
        return word1.size() +word2.size()  - 2* dp[word2.size()];
    }
};
```
      