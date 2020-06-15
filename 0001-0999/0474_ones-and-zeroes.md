[474.ones-and-zeroes](https://leetcode.com/problems/ones-and-zeroes/)  

Given an array, `strs`, with strings consisting of only `0s` and `1s`. Also two integers `m` and `n`.

Now your task is to find the maximum number of strings that you can form with given **m** `0s` and **n** `1s`. Each `0` and `1` can be used at most **once**.

**Example 1:**

**Input:** strs = \["10","0001","111001","1","0"\], m = 5, n = 3
**Output:** 4
**Explanation:** This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are "10","0001","1","0".

**Example 2:**

**Input:** strs = \["10","0","1"\], m = 1, n = 1
**Output:** 2
**Explanation:** You could form "10", but then you'd have nothing left. Better form "0" and "1".

**Constraints:**

*   `1 <= strs.length <= 600`
*   `1 <= strs[i].length <= 100`
*   `strs[i]` consists only of digits '0' and '1'.
*   `1 <= m, n <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(auto &str: strs){
            int z = 0, o = 0;
            for(char c : str)
                c == '0' ? ++z : ++o;
            for(int i = m; i >= z; --i) {
                for(int j = n; j >= o; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-z][j-o] + 1);
                }
            }
        }
        return dp[m][n];
    }
    /*
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int, int> memo, dp;
        int ans = 0;
        memo[0] = 0;
        dp[0] = 0;
        for(int i = 1; i <= strs.size(); ++i) {
            int z = 0, o = 0;
            for(char c : strs[i-1])
                c == '0' ? ++z : ++o;
            for(auto &it : memo) {
                int nm = (it.first & 0xFFFF) + z;
                int nn = (it.first >> 16) + o;
                if(nm > m || nn > n) continue;
                int hash = nm | (nn << 16);
                dp[hash] = max(dp[hash], it.second + 1);
                ans = max(ans, dp[hash]);
            }
            memo = dp;
        }
        return ans;
    }*/
};
```
      