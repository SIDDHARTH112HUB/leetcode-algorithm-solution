[343.integer-break](https://leetcode.com/problems/integer-break/)  

Given a positive integer _n_, break it into the sum of **at least** two positive integers and maximize the product of those integers. Return the maximum product you can get.

**Example 1:**

**Input:** 2
**Output:** 1
**Explanation:** 2 = 1 + 1, 1 × 1 = 1.

**Example 2:**

**Input:** 10
**Output:** 36
**Explanation:** 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

**Note**: You may assume that _n_ is not less than 2 and not larger than 58.  



**Solution:**  

```cpp
class Solution {
public:
    map<int, int> dp;
    int integerBreak(int n,int begin=1) {
        int dp[n+5] = {0};
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        for( int i = 5; i<=n; i++){
            for( int j = 1; j<i; j++){
                dp[i] = max(max(dp[i-j],i-j) * max(dp[j],j), dp[i]);
            }
        }
        return dp[n];
    }
};
```
      