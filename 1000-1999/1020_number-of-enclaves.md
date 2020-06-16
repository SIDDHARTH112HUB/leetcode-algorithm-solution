[1020.number-of-enclaves](https://leetcode.com/problems/number-of-enclaves/)  

Given a 2D array `A`, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we **cannot** walk off the boundary of the grid in any number of moves.

**Example 1:**

  
**Input:** \[\[0,0,0,0\],\[1,0,1,0\],\[0,1,1,0\],\[0,0,0,0\]\]
  
**Output:** 3
  
**Explanation:** 
  
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.

**Example 2:**

  
**Input:** \[\[0,1,1,0\],\[0,0,1,0\],\[0,0,1,0\],\[0,0,0,0\]\]
  
**Output:** 0
  
**Explanation:** 
  
All 1s are either on the boundary or can reach the boundary.
  

**Note:**

1.  `1 <= A.length <= 500`
2.  `1 <= A[i].length <= 500`
3.  `0 <= A[i][j] <= 1`
4.  All rows have the same size.  



**Solution:**  

```cpp
class Solution {
public:
    int m;
    int n;
    int numEnclaves(vector<vector<int>>& A) {
        m = A.size();
        n = A[0].size();
        for (int i = 0; i < m; i++) {
            if(A[i][0] == 1)
                solve(A, i, 0);
            if(A[i][n-1] == 1)
                solve(A, i, n-1);
        }
        for (int i = 0; i < n; i++) {
            if (A[0][i] == 1)
                solve(A, 0, i);
            if (A[m-1][i] == 1)
                solve(A, m-1, i);
        }
        int ans = 0;
        for(auto &row:A)
            for( int n : row )
                if(n==1) ans++;
        return ans;
    }
    
    void solve(vector<vector<int>>& A, int x, int y) {
        if (x >= m || y >= n || x <0 || y < 0 || A[x][y] == 0)
            return;
        A[x][y] = 0;
        solve(A, x+1, y);
        solve(A, x, y+1);
        solve(A, x, y-1);
        solve(A, x-1, y);
    }
};
```
      