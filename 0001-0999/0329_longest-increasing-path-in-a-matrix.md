[329.longest-increasing-path-in-a-matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)  

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

**Example 1:**

**Input:** nums = 
\[
  \[9,9,4\],
  \[6,6,8\],
  \[2,1,1\]
\] 
**Output:** 4 
**Explanation:** The longest increasing path is `[1, 2, 6, 9]`.

**Example 2:**

**Input:** nums = 
\[
  \[3,4,5\],
  \[3,2,6\],
  \[2,2,1\]
\] 
**Output:** 4 
**Explanation:** The longest increasing path is `[3, 4, 5, 6]`. Moving diagonally is not allowed.  



**Solution:**  

```cpp
class Solution {
public:
         unordered_map<int, unordered_map<int, int> > memo;
     int m, n;
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        // write your code here
        m = matrix.size();
        if( m == 0 ) return 0;
        n = matrix[0].size();
        if( n == 0 ) return 0;
        int ans = 0;
        for( int i = 0; i < m; i++){
            for( int j = 0; j< n; j++){
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>> &matrix, int x, int y){
        if( memo[x].count(y) ) return memo[x][y];
        int d[5] = {0,1,0,-1,0};
        int res = 1;
        for( int i = 0; i< 4; i++){
            int nx = d[i] + x;
            int ny = d[i+1] +y;
            if( nx < 0|| ny <0||nx >=m ||ny>=n || matrix[nx][ny] <= matrix[x][y])
                continue;
            res = max( res, dfs(matrix, nx, ny)+1);
        }
        memo[x][y] = res;
        return res;
    }
};
```
      