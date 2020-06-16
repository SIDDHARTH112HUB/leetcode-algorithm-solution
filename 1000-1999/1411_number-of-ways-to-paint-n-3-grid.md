[1411.number-of-ways-to-paint-n-3-grid](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/)  

You have a `grid` of size `n x 3` and you want to paint each cell of the grid with exactly one of the three colours: **Red**, **Yellow** or **Green** while making sure that no two adjacent cells have the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).

You are given `n` the number of rows of the grid.

Return _the number of ways_ you can paint this `grid`. As the answer may grow large, the answer **must be** computed modulo `10^9 + 7`.

**Example 1:**

  
**Input:** n = 1
  
**Output:** 12
  
**Explanation:** There are 12 possible way to paint the grid as shown:
  
![](https://assets.leetcode.com/uploads/2020/03/26/e1.png)
  

**Example 2:**

  
**Input:** n = 2
  
**Output:** 54
  

**Example 3:**

  
**Input:** n = 3
  
**Output:** 246
  

**Example 4:**

  
**Input:** n = 7
  
**Output:** 106494
  

**Example 5:**

  
**Input:** n = 5000
  
**Output:** 30228214
  

**Constraints:**

*   `n == grid.length`
*   `grid[i].length == 3`
*   `1 <= n <= 5000`  



**Solution:**  

```cpp
class Solution {
public:
    int dp[5001][4][4][4] = {};
    int numOfWays(int n) {
        return dfs(n, 0, 0, 0);
    }
    
    int dfs(int n, int a, int b, int c) {
        if(n == 0) return 1;
        if(dp[n][a][b][c]) return dp[n][a][b][c];
        vector<int> col = {1,2,3};
        int ans = 0;
        for(auto a0 : col) {
            if(a == a0) continue;
            for(auto b0 : col) {
                if(b0 == b || b0 == a0) continue;
                for(auto c0 : col) {
                    if(c0 == c || b0 == c0) continue;
                    ans += dfs(n-1, a0, b0, c0);
                    ans %= 1000000007;
                }
            }
        }
        dp[n][a][b][c] = ans;
        return ans;
    }
};

```
      