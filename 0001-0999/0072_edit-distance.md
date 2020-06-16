[72.edit-distance](https://leetcode.com/problems/edit-distance/)  

Given two words _word1_ and _word2_, find the minimum number of operations required to convert _word1_ to _word2_.

You have the following 3 operations permitted on a word:

1.  Insert a character
2.  Delete a character
3.  Replace a character

**Example 1:**

  
**Input:** word1 = "horse", word2 = "ros"
  
**Output:** 3
  
**Explanation:** 
  
horse -> rorse (replace 'h' with 'r')
  
rorse -> rose (remove 'r')
  
rose -> ros (remove 'e')
  

**Example 2:**

  
**Input:** word1 = "intention", word2 = "execution"
  
**Output:** 5
  
**Explanation:** 
  
intention -> inention (remove 't')
  
inention -> enention (replace 'i' with 'e')
  
enention -> exention (replace 'n' with 'x')
  
exention -> exection (replace 'n' with 'c')
  
exection -> execution (insert 'u')  



**Solution:**  

```cpp
class Solution {
public:
    int minDistance1(string word1, string word2) {
        
        int dp[word1.size()+1][word2.size()+1];
        memset(dp, 0 , sizeof(dp));
        for( int i = 0; i<=word1.size(); i++ ){
            dp[i][0] = i;
        }
        
        for( int i = 0; i<=word2.size(); i++ )
            dp[0][i] = i;

        for( int i = 0; i<word1.size(); i++){
            for( int j =0; j<word2.size(); j++){
                if( word1[i] == word2[j] )
                    dp[i+1][j+1] = dp[i][j];
                else{
                    dp[i+1][j+1] = min(min(dp[i][j+1]+1, dp[i+1][j]+1), dp[i][j]+1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
    int dp[1001][1001];
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return dfs(word1, word2, 0, 0);
    }
    int dfs(string &w1, string &w2, int i , int j) {
        if(i >= w1.size()) return w2.size() - j;
        if(j >= w2.size()) return w1.size() - i;
        int res = INT_MAX;
        if(dp[i][j] >= 0) return dp[i][j];
        if(w1[i] == w2[j])
            res = dfs(w1, w2, i + 1, j + 1);
        else
            res = min(res, min(min(1 + dfs(w1, w2, i + 1, j), 1 + dfs(w1, w2, i, j + 1)), 1 + dfs(w1, w2, i + 1, j + 1) ));
        return dp[i][j] =res;
    }
};
```
      