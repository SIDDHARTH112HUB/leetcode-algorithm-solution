[688.knight-probability-in-chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/)  

On an `N`x`N` chessboard, a knight starts at the `r`\-th row and `c`\-th column and attempts to make exactly `K` moves. The rows and columns are 0 indexed, so the top-left square is `(0, 0)`, and the bottom-right square is `(N-1, N-1)`.

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

![](https://assets.leetcode.com/uploads/2018/10/12/knight.png)

Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly `K` moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

**Example:**

  
**Input:** 3, 2, 0, 0
  
**Output:** 0.0625
  
**Explanation:** There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
  
From each of those positions, there are also two moves that will keep the knight on the board.
  
The total probability the knight stays on the board is 0.0625.
  

**Note:**

*   `N` will be between 1 and 25.
*   `K` will be between 0 and 100.
*   The knight always initially starts on the board.  



**Solution:**  

```cpp
class Solution {
public:
    double dfs( int N, int K, int r, int c, vector< vector<vector<double> > >& dp){
        if( K<= 0){
            return 1.0;
        }
        if( dp[K][r][c] > -1 )
            return dp[K][r][c];
        double val = 0.0;
        for(int i =-2;i<=2;i++){
            for(int j =-2;j<=2;j++){
                if( abs(i) != abs(j) && i!=0 && j!=0 ){
                    int r1 = r+i;
                    int c1 = c+j;
                    if( c1 < 0 || r1<0 || c1>=N || r1>=N){
                        
                    }else
                        val += (this->dfs(N, K-1, r1, c1, dp) / 8.0);
                }
            }
        }
        dp[K][r][c] = val;
        return val;
    }
    double knightProbability1(int N, int K, int r, int c) {
        if( K == 0 ) return 1;
        vector< vector< vector<double> > > dp = vector< vector< vector<double> > >( K+1, vector< vector<double> >( N, vector<double>( N, -1.0 ) ) );
        return this->dfs(N, K, r, c, dp);
    }
    
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double> > dp(N, vector<double>(N));
        dp[r][c] = 1.0;
        for(int k = 0; k < K; ++k) {
            vector<vector<double> > tmp(N, vector<double>(N));
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    for(int x =-2; x<=2; x++){
                        for(int y =-2; y<=2; y++){
                            if( abs(x) != abs(y) && x!=0 && y!=0 ){
                                int r1 = i + x;
                                int c1 = j + y;
                                if( c1 < 0 || r1<0 || c1>=N || r1>=N) continue;
                                tmp[r1][c1] += dp[i][j] / 8.0;
                            }
                        }
                    }
                }
            }
            dp = tmp;
        }
        double ans = 0;
        for(auto &row : dp) {
            for(auto &n : row)
                ans += n;
        }
        return ans;
    }
};


```
      