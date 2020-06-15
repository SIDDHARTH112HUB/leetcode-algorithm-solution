[62.unique-paths](https://leetcode.com/problems/unique-paths/)  

A robot is located at the top-left corner of a _m_ x _n_ grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

![](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)  
Above is a 7 x 3 grid. How many possible unique paths are there?

**Example 1:**

**Input:** m = 3, n = 2
**Output:** 3
**Explanation:**
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

**Example 2:**

**Input:** m = 7, n = 3
**Output:** 28

**Constraints:**

*   `1 <= m, n <= 100`
*   It's guaranteed that the answer will be less than or equal to `2 * 10 ^ 9`.  



**Solution:**  

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m][n];
        memset(f, 0, sizeof(f));
        for( int i = 0 ; i < m; i++)
        {
            f[i][0] = 1;
            f[i][n-1] = 1;
        }
        for( int i = 0 ; i < n; i++)
        {
            f[0][i] = 1;
            f[m-1][i] = 1;
        }
        for( int i =1; i< m ; i++)
        {
            for( int j =1; j< n ; j++)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};
```
      