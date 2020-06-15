[576.out-of-boundary-paths](https://leetcode.com/problems/out-of-boundary-paths/)  

There is an **m** by **n** grid with a ball. Given the start coordinate **(i,j)** of the ball, you can move the ball to **adjacent** cell or cross the grid boundary in four directions (up, down, left, right). However, you can **at most** move **N** times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

**Example 1:**

**Input:** m = 2, n = 2, N = 2, i = 0, j = 0
**Output:** 6
**Explanation:**
![](https://assets.leetcode.com/uploads/2018/10/13/out_of_boundary_paths_1.png)

**Example 2:**

**Input:** m = 1, n = 3, N = 3, i = 0, j = 1
**Output:** 12
**Explanation:**
![](https://assets.leetcode.com/uploads/2018/10/12/out_of_boundary_paths_2.png)

**Note:**

1.  Once you move the ball out of boundary, you cannot move it back.
2.  The length and height of the grid is in range \[1,50\].
3.  N is in range \[0,50\].  



**Solution:**  

```cpp
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int M = 1000000007;
        int dp[51][51][51]={0};
        dp[i][j][0] = 1;
        int ans = 0;
        for( int k = 1; k<=N; k++){
            for( int i = 0; i<m;i++){
                for( int j = 0; j<n;j++){
                    int dx[] = {1,-1,0,0};
                    int dy[] = {0,0,1,-1};
                    for( int l = 0; l<4; l++){
                        int nx = i+dx[l];
                        int ny = j+dy[l];
                        if( nx >= 0 && ny >=0 && nx <m && ny < n ){
                            dp[nx][ny][k] = (dp[i][j][k-1] + dp[nx][ny][k])%M;
                        }else{
                            ans = ( ans + dp[i][j][k-1] )%M;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```
      