[1478.allocate-mailboxes](https://leetcode.com/problems/allocate-mailboxes/)  

Given the array `houses` and an integer `k`. where `houses[i]` is the location of the ith house along a street, your task is to allocate `k` mailboxes in the street.

Return the **minimum** total distance between each house and its nearest mailbox.

The answer is guaranteed to fit in a 32-bit signed integer.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/05/07/sample_11_1816.png)

  
**Input:** houses = \[1,4,8,10,20\], k = 3
  
**Output:** 5
  
**Explanation:** Allocate mailboxes in position 3, 9 and 20.
  
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/05/07/sample_2_1816.png)**

  
**Input:** houses = \[2,3,5,12,18\], k = 2
  
**Output:** 9
  
**Explanation:** Allocate mailboxes in position 3 and 14.
  
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
  

**Example 3:**

  
**Input:** houses = \[7,4,6,1\], k = 1
  
**Output:** 8
  

**Example 4:**

  
**Input:** houses = \[3,6,14,10\], k = 4
  
**Output:** 0
  

**Constraints:**

*   `n == houses.length`
*   `1 <= n <= 100`
*   `1 <= houses[i] <= 10^4`
*   `1 <= k <= n`
*   Array `houses` contain unique integers.  



**Solution:**  

```cpp
#define MAXN 10020
#define MAXM 2010000
class Solution {
public:
    int dp[101][101];
    int cost[101][101];
    int minDistance(vector<int>& houses, int mailCnt) {
        sort(houses.begin(), houses.end());
        memset(dp, -1, sizeof(dp));
        memset(cost, 0, sizeof(cost));
        int n = houses.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = i; k <= j; ++k) {
                    cost[i][j] += abs(houses[(i + j)/ 2] - houses[k]);
                }
            }
        }
        return dfs(houses, 0, houses.size(), mailCnt);
    }
    
    int dfs(vector<int> &h, int i, int n, int mailCnt) {
        if(mailCnt == 0 && i == n) return 0;
        if(mailCnt == 0 || i == n) return 1e+9;
        if(dp[i][mailCnt] >= 0) return dp[i][mailCnt];
        int res = 1e+9;
        for(int k = i; k < n; ++k) {
            int mid = (i + k) / 2;
            res = min(res, cost[i][k] + dfs(h, k + 1, n, mailCnt - 1));
        }
        return dp[i][mailCnt] = res;
    }
};
```
      