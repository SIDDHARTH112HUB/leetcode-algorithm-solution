[959.regions-cut-by-slashes](https://leetcode.com/problems/regions-cut-by-slashes/)  

In a N x N `grid` composed of 1 x 1 squares, each 1 x 1 square consists of a `/`, `\`, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a `\` is represented as `"\\"`.)

Return the number of regions.

**Example 1:**

**Input:** \[
  " /",
  "/ "
\]
**Output:** 2
**Explanation:** The 2x2 grid is as follows:
![](https://assets.leetcode.com/uploads/2018/12/15/1.png)

**Example 2:**

**Input:** \[
  " /",
  "  "
\]
**Output:** 1
**Explanation:** The 2x2 grid is as follows:
![](https://assets.leetcode.com/uploads/2018/12/15/2.png)

**Example 3:**

**Input:** \[
  "\\\\/",
  "/\\\\"
\]
**Output:** 4
**Explanation:** (Recall that because \\ characters are escaped, "\\\\/" refers to \\/, and "/\\\\" refers to /\\.)
The 2x2 grid is as follows:
![](https://assets.leetcode.com/uploads/2018/12/15/3.png)

**Example 4:**

**Input:** \[
  "/\\\\",
  "\\\\/"
\]
**Output:** 5
**Explanation:** (Recall that because \\ characters are escaped, "/\\\\" refers to /\\, and "\\\\/" refers to \\/.)
The 2x2 grid is as follows:
![](https://assets.leetcode.com/uploads/2018/12/15/4.png)

**Example 5:**

**Input:** \[
  "//",
  "/ "
\]
**Output:** 3
**Explanation:** The 2x2 grid is as follows:
![](https://assets.leetcode.com/uploads/2018/12/15/5.png)

**Note:**

1.  `1 <= grid.length == grid[0].length <= 30`
2.  `grid[i][j]` is either `'/'`, `'\'`, or `' '`.  



**Solution:**  

```cpp
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int> > g(n*3, vector<int>(n*3));
        for( int i = 0; i< n ; i++){
            for( int j = 0; j < n ; j++){
                if( grid[i][j] == '\\'){
                    g[i*3][j*3] = -1;
                    g[i*3+1][j*3+1] = -1;
                    g[i*3+2][j*3+2] = -1;
                }else if( grid[i][j] == '/'){
                    g[i*3+2][j*3] = -1;
                    g[i*3+1][j*3+1] = -1;
                    g[i*3][j*3+2] = -1;
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < g.size(); i++){
            for( int j = 0; j < g.size(); j++){
                if( g[i][j] == 0 ){
                    dfs( g, i, j);
                    ++ans;
                }
            }
        }
        
        return ans;
    }
    
    void dfs( vector<vector<int> > &g, int x, int y){
        g[x][y] = -1;
        int d[5] = {0,1,0,-1,0};
        for( int i = 0; i< 4; i++){
            int nx = d[i] +x;
            int ny = d[i+1]+y;
            if( nx < 0 || ny < 0 || nx >= g.size() || ny >= g.size() || g[nx][ny] == -1 )
                continue;
            dfs( g, nx, ny);
        }
    }
};
```
      