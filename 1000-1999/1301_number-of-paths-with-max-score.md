[1301.number-of-paths-with-max-score](https://leetcode.com/problems/number-of-paths-with-max-score/)  

You are given a square `board` of characters. You can move on the board starting at the bottom right square marked with the character `'S'`.

You need to reach the top left square marked with the character `'E'`. The rest of the squares are labeled either with a numeric character `1, 2, ..., 9` or with an obstacle `'X'`. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, **taken modulo `10^9 + 7`**.

In case there is no path, return `[0, 0]`.

**Example 1:**

**Input:** board = \["E23","2X2","12S"\]
  
**Output:** \[7,1\]
  

**Example 2:**

**Input:** board = \["E12","1X1","21S"\]
  
**Output:** \[4,2\]
  

**Example 3:**

**Input:** board = \["E11","XXX","11S"\]
  
**Output:** \[0,0\]
  

**Constraints:**

*   `2 <= board.length == board[i].length <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        for(auto &row : board) {
            reverse(row.begin(), row.end());
        }
        long long M = 1e9 + 7;
        reverse(board.begin(), board.end());
        int m = board.size(), n = board[0].size();
        long long dp[m+1][n+1][2];
        memset(dp, 0, sizeof(dp));
        dp[1][1][1] = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(board[i-1][j-1] == 'X') continue;
                if(i == 1 && j == 1) continue;
                long long mx = max(max(dp[i-1][j-1][0], dp[i-1][j][0]), dp[i][j- 1][0]);
                if(board[i-1][j-1] != 'E')
                    dp[i][j][0] = mx + board[i-1][j-1] - '0';
                else
                    dp[i][j][0] = mx;
                if(dp[i-1][j-1][0] == mx) {
                    dp[i][j][1] += dp[i-1][j-1][1];
                }
                if(dp[i][j-1][0] == mx) {
                    dp[i][j][1] += dp[i][j-1][1];
                }
                if(dp[i-1][j][0] == mx) {
                    dp[i][j][1] += dp[i-1][j][1];
                }
                dp[i][j][1] %= M;
            }
        }
        return {dp[m][n][1] == 0 ? 0 : dp[m][n][0], dp[m][n][1]};
    }
};
```
      