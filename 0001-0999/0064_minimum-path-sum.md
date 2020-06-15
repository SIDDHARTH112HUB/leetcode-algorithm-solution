[64.minimum-path-sum](https://leetcode.com/problems/minimum-path-sum/)  

Given a _m_ x _n_ grid filled with non-negative numbers, find a path from top left to bottom right which _minimizes_ the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

**Example:**

**Input:**
\[
  \[1,3,1\],
  \[1,5,1\],
  \[4,2,1\]
\]
**Output:** 7
**Explanation:** Because the path 1→3→1→1→1 minimizes the sum.  



**Solution:**  

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if( m == 0 ) return 0;
        int n = grid[0].size();
        int a[m][n];
        a[0][0] = grid[0][0];
        for( int i = 1; i< m ; i++ )
        {
            a[i][0] = grid[i][0] + a[i-1][0];
        }
        for( int i = 1; i< n ; i++ )
        {
            a[0][i] = grid[0][i] + a[0][i-1];
        }
        for( int i = 1; i < m; i++)
        {
            for( int j = 1; j < n; j++)
            {
                int num1 = a[i-1][j] + grid[i][j];
                int num2 = a[i][j-1] + grid[i][j];
                a[i][j] = num1 > num2? num2:num1;
            }
        }
        return a[m-1][n-1];
    }
};
```
      