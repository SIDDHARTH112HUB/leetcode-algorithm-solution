[1240.tiling-a-rectangle-with-the-fewest-squares](https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/)  

Given a rectangle of size `n` x `m`, find the minimum number of integer-sided squares that tile the rectangle.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/10/17/sample_11_1592.png)

  
**Input:** n = 2, m = 3  
**Output:** 3  
**Explanation:** `3` squares are necessary to cover the rectangle.  
`2` (squares of `1x1`)  
`1` (square of `2x2`)

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/10/17/sample_22_1592.png)

  
**Input:** n = 5, m = 8  
**Output:** 5  

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/10/17/sample_33_1592.png)

  
**Input:** n = 11, m = 13  
**Output:** 6  

**Constraints:**

*   `1 <= n <= 13`
*   `1 <= m <= 13`  



**Solution:**  

```cpp
class Solution {
public:
    int tilingRectangle(int n, int m) {
        int dp[15][15];
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
            dp[i][j]=i==j?1:i*j;
            for(int p=1;p<i;p++)dp[i][j]=min(dp[i][j],dp[p][j]+dp[i-p][j]);
            for(int p=1;p<j;p++)dp[i][j]=min(dp[i][j],dp[i][p]+dp[i][j-p]);
            for(int x=2;x<i;x++)for(int y=2;y<j;y++){
                dp[i][j]=min(dp[i][j],dp[x-1][y]+dp[x][j-y]+dp[i-x+1][y-1]+dp[i-x][j-y+1]+1);
            }
        }return dp[n][m];
    }
};
```
      