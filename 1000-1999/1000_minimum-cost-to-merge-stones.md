[1000.minimum-cost-to-merge-stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/)  

There are `N` piles of stones arranged in a row.  The `i`\-th pile has `stones[i]` stones.

A _move_ consists of merging **exactly `K` consecutive** piles into one pile, and the cost of this move is equal to the total number of stones in these `K` piles.

Find the minimum cost to merge all piles of stones into one pile.  If it is impossible, return `-1`.

**Example 1:**

  
**Input:** stones = \[3,2,4,1\], K = 2
  
**Output:** 20
  
**Explanation:** 
  
We start with \[3, 2, 4, 1\].
  
We merge \[3, 2\] for a cost of 5, and we are left with \[5, 4, 1\].
  
We merge \[4, 1\] for a cost of 5, and we are left with \[5, 5\].
  
We merge \[5, 5\] for a cost of 10, and we are left with \[10\].
  
The total cost was 20, and this is the minimum possible.
  

**Example 2:**

  
**Input:** stones = \[3,2,4,1\], K = 3
  
**Output:** \-1
  
**Explanation:** After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
  

**Example 3:**

  
**Input:** stones = \[3,5,1,2,6\], K = 3
  
**Output:** 25
  
**Explanation:** 
  
We start with \[3, 5, 1, 2, 6\].
  
We merge \[5, 1, 2\] for a cost of 8, and we are left with \[3, 8, 6\].
  
We merge \[3, 8, 6\] for a cost of 17, and we are left with \[17\].
  
The total cost was 25, and this is the minimum possible.
  

**Note:**

*   `1 <= stones.length <= 30`
*   `2 <= K <= 30`
*   `1 <= stones[i] <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > m;
    int mergeStones(vector<int>& stones, int K) {
        
        int n = stones.size();
        if((n-1) % (K-1) != 0) return -1;
        int dp[n][n];
        int mx = 1000000;
        memset(dp, 8, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1; i < n; ++i) {
            dp[i][i] = 0;
            stones[i] += stones[i-1];
        }
        return dfs(stones, K, 0, n-1);
        for(int l = 2; l <= n; ++l) {
            for(int i = 0; i + l <= n; ++i) {
                int j = i + l - 1;
                for(int m = i; m <j; m+=K-1)
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j]);
                
                if((l-1) % (K-1) == 0){
                    dp[i][j] = dp[i][j] + stones[j] - (i > 0?stones[i-1]:0);
                }
            }
        }
        return dp[0][n-1];
    }
    
    int dfs(vector<int>& stones, int K, int i, int j) {
        int l = j - i + 1;
        //if(l < K) return 0;
        if( i == j) return 0;
        if(m[i].count(j)) return m[i][j];
        
        int res = INT_MAX;
        for(int k = i; k <j; k += K-1) {
            res = min(res, dfs(stones, K, i, k) + dfs(stones, K, k+1, j));
        }
        if((l - 1) % (K-1) == 0){
            res += stones[j] - (i > 0?stones[i-1]:0);
            
        }
        return m[i][j] = res;
    }
};
```
      