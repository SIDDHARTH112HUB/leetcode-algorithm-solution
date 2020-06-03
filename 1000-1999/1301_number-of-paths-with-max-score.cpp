//Link: https://leetcode.com/problems/number-of-paths-with-max-score/ 
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