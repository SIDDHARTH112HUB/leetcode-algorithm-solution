[279.perfect-squares](https://leetcode.com/problems/perfect-squares/)  

Given a positive integer _n_, find the least number of perfect square numbers (for example, `1, 4, 9, 16, ...`) which sum to _n_.

**Example 1:**

**Input:** _n_ = `12`
**Output:** 3 
**Explanation:** `12 = 4 + 4 + 4.`

**Example 2:**

**Input:** _n_ = `13`
**Output:** 2
**Explanation:** `13 = 4 + 9.`  



**Solution:**  

```cpp
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1] = {0};
        for(int i = 1; i <=n; ++i){
            dp[i] = i;
            for(int j = 2; j <= sqrt(i); ++j) {
                dp[i] = min(dp[i], 1  + dp[i - j*j]);
            }
        }
        return dp[n];
    }
};
```
      