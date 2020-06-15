[629.k-inverse-pairs-array](https://leetcode.com/problems/k-inverse-pairs-array/)  

Given two integers `n` and `k`, find how many different arrays consist of numbers from `1` to `n` such that there are exactly `k` inverse pairs.

We define an inverse pair as following: For `ith` and `jth` element in the array, if `i` < `j` and `a[i]` > `a[j]` then it's an inverse pair; Otherwise, it's not.

Since the answer may be very large, the answer should be modulo 109 + 7.

**Example 1:**

**Input:** n = 3, k = 0
**Output:** 1
**Explanation:** 
Only the array \[1,2,3\] which consists of numbers from 1 to 3 has exactly 0 inverse pair.

**Example 2:**

**Input:** n = 3, k = 1
**Output:** 2
**Explanation:** 
The array \[1,3,2\] and \[2,1,3\] have exactly 1 inverse pair.

**Note:**

1.  The integer `n` is in the range \[1, 1000\] and `k` is in the range \[0, 1000\].  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > memo;
    int kInversePairs(int n, int k) {
        //return dfs(n, k);
        int dp[n+1][k+1] = {0};
        //dp[1][1] = 1;
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        int M = 1000000007;
        //for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i][0] = 1;
            int sum = 1;
            for(int m = 1; m <= k; ++m) {
                if(m >= i) sum -= dp[i-1][m-i];
                if(sum < 0) sum = (sum + M) %M;
                (sum += dp[i-1][m]) %= M;
                dp[i][m] += sum;
            }
        }
        return dp[n][k];
    }
    int dfs(int n, int k){
        if(k == 0) return 1;
        if(n == 1) return 1;
        if(memo[n].count(k)) return memo[n][k];
        int res = 0;
        for(int i = 0; i <= min(k, n); i++) {
            res += dfs(n-1, i) + min(k, n) - i;
        }
        memo[n][k] = res;
        return res;
    }
};
```
      