[63.unique-paths-ii](https://leetcode.com/problems/unique-paths-ii/)  

A robot is located at the top-left corner of a _m_ x _n_ grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

![](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

An obstacle and empty space is marked as `1` and `0` respectively in the grid.

**Note:** _m_ and _n_ will be at most 100.

**Example 1:**

  
**Input:** \[
  
  \[0,0,0\],
  
  \[0,1,0\],
  
  \[0,0,0\]
  
\]
  
**Output:** 2
  
**Explanation:**
  
There is one obstacle in the middle of the 3x3 grid above.
  
There are two ways to reach the bottom-right corner:
  
1. Right -> Right -> Down -> Down
  
2. Down -> Down -> Right -> Right  



**Solution:**  

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if( m == 0 ) return 0;
        int n = obstacleGrid[0].size();
        int grid[m][n];
        memset(grid, 0, sizeof(int)*m*n);
        for( int i = 0; i<m; i++)
        {
            if( obstacleGrid[i][0] == 1)
            {
                break;
            }
            else
                grid[i][0] = 1;
        }
        for( int i = 0; i<n; i++)
        {
            if( obstacleGrid[0][i] == 1)
            {
                break;
            }
            else
                grid[0][i] = 1;
        }
        for( int i = 1; i<m ;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1)
                    grid[i][j] = 0;
                else
                    grid[i][j] = grid[i-1][j] +grid[i][j-1];
            }
        }
        //delete[] grid;
        return grid[m-1][n-1];
    }
};
```
      