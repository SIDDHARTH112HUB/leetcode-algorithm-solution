[712.minimum-ascii-delete-sum-for-two-strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)  

Given two strings `s1, s2`, find the lowest ASCII sum of deleted characters to make two strings equal.

**Example 1:**  

  
**Input:** s1 = "sea", s2 = "eat"
  
**Output:** 231
  
**Explanation:** Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
  
Deleting "t" from "eat" adds 116 to the sum.
  
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
  

**Example 2:**  

  
**Input:** s1 = "delete", s2 = "leet"
  
**Output:** 403
  
**Explanation:** Deleting "dee" from "delete" to turn the string into "let",
  
adds 100\[d\]+101\[e\]+101\[e\] to the sum.  Deleting "e" from "leet" adds 101\[e\] to the sum.
  
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
  
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
  

**Note:**

*   `0 < s1.length, s2.length <= 1000`.
*   All elements of each string will have an ASCII value in `[97, 122]`.  



**Solution:**  

```cpp
class Solution {
public:
    int dp[1001][1001];
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return dfs(s1, s2, 0, 0);
    }
    
    int dfs(string &s1, string &s2, int i, int j) {
        if(i == s1.size() ) {
            return accumulate(s2.begin() + j, s2.end(), 0);
        }
        if(j == s2.size()) {
            return accumulate(s1.begin() + i, s1.end(), 0);
        }
        if(dp[i][j] >= 0) return dp[i][j];
        int res = INT_MAX;
        if(s1[i] == s2[j]) {
            res = min(res, dfs(s1, s2, i + 1, j + 1));
        }else {
            res = min(res, s1[i] + dfs(s1, s2, i + 1, j));
            res = min(res, s2[j] + dfs(s1, s2, i, j + 1));
        }
        return dp[i][j] = res;
    }
};
```
      