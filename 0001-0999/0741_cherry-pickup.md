[741.cherry-pickup](https://leetcode.com/problems/cherry-pickup/)  

In a N x N `grid` representing a field of cherries, each cell is one of three possible integers.

*   0 means the cell is empty, so you can pass through;
*   1 means the cell contains a cherry, that you can pick up and pass through;
*   \-1 means the cell contains a thorn that blocks your way.

Your task is to collect maximum number of cherries possible by following the rules below:

*   Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
*   After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
*   When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
*   If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.

**Example 1:**

  
**Input:** grid =
  
\[\[0, 1, -1\],
  
 \[1, 0, -1\],
  
 \[1, 1,  1\]\]
  
**Output:** 5
  
**Explanation:** 
  
The player started at (0, 0) and went down, down, right right to reach (2, 2).
  
4 cherries were picked up during this single trip, and the matrix becomes \[\[0,1,-1\],\[0,0,-1\],\[0,0,0\]\].
  
Then, the player went left, up, up, left to return home, picking up one more cherry.
  
The total number of cherries picked up is 5, and this is the maximum possible.
  

**Note:**

*   `grid` is an `N` by `N` 2D array, with `1 <= N <= 50`.
*   Each `grid[i][j]` is an integer in the set `{-1, 0, 1}`.
*   It is guaranteed that grid\[0\]\[0\] and grid\[N-1\]\[N-1\] are not -1.  



**Solution:**  

```cpp
class Solution {
public:
    int n;
    vector<vector<vector<int>>> m;
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, helper(grid,0,0,0));
    }
    int helper(vector<vector<int>>& grid, int x1, int y1, int x2){
        int y2 = x1+y1 - x2;
        if( x1 >= n || y1 >=n || x2 >= n || y2>=n )
            return -1;
        
        if( grid[x1][y1] < 0 || grid[x2][y2] < 0 ) return -1;
        if( x1 == n-1 && y1==n-1) return grid[x1][y1];
        int memo = m[x1][y1][x2];
        if( memo != INT_MIN ) return memo;
        int ans = max( max(helper(grid, x1+1, y1, x2), helper(grid, x1, y1+1, x2) ), 
                       max(helper(grid, x1+1, y1, x2+1), helper(grid, x1, y1+1, x2+1) ) );
        if( ans < 0 ){
            m[x1][y1][x2] = -1;
            return -1;
        }
        ans += grid[x1][y1];
        if( x1 != x2 )
            ans += grid[x2][y2];
        m[x1][y1][x2] = ans;
        return ans;
    }
};
```
      