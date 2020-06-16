[1434.number-of-ways-to-wear-different-hats-to-each-other](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/)  

There are `n` people and 40 types of hats labeled from 1 to 40.

Given a list of list of integers `hats`, where `hats[i]` is a list of all hats preferred by the `i-th` person.

Return the number of ways that the n people wear different hats to each other.

Since the answer may be too large, return it modulo `10^9 + 7`.

**Example 1:**

  
**Input:** hats = \[\[3,4\],\[4,5\],\[5\]\]
  
**Output:** 1
  
**Explanation:** There is only one way to choose hats given the conditions. 
  
First person choose hat 3, Second person choose hat 4 and last one hat 5.

**Example 2:**

  
**Input:** hats = \[\[3,5,1\],\[3,5\]\]
  
**Output:** 4
  
**Explanation:** There are 4 ways to choose hats
  
(3,5), (5,3), (1,3) and (1,5)
  

**Example 3:**

  
**Input:** hats = \[\[1,2,3,4\],\[1,2,3,4\],\[1,2,3,4\],\[1,2,3,4\]\]
  
**Output:** 24
  
**Explanation:** Each person can choose hats labeled from 1 to 4.
  
Number of Permutations of (1,2,3,4) = 24.
  

**Example 4:**

  
**Input:** hats = \[\[1,2,3\],\[2,3,5,6\],\[1,3,7,9\],\[1,8,9\],\[2,5,7\]\]
  
**Output:** 111
  

**Constraints:**

*   `n == hats.length`
*   `1 <= n <= 10`
*   `1 <= hats[i].length <= 40`
*   `1 <= hats[i][j] <= 40`
*   `hats[i]` contains a list of **unique** integers.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> hat[41];
    map<int, map<int, int> > dp;
    int all = 0;
    int numberWays(vector<vector<int>>& hats) {
        for(int i = 0; i < hats.size(); ++i) {
            for(auto h : hats[i])
                hat[h].push_back(i);
        }
        all = (1 << (hats.size()))-1;
        return dfs(0, 0);
    }
    
    int dfs(int mask, int idx) {
        if(idx > 40) return mask == all;
        if(dp[idx].count(mask)) return dp[idx][mask];
        int ans = dfs( mask, idx + 1);
        for(auto n : hat[idx]) {
            if(mask & (1 << n)) continue;
            ans += dfs(mask | ( 1 << n), idx + 1);
            ans %= 1000000007;
        }
        dp[idx][mask] = ans;
        return ans;
    }
};
```
      