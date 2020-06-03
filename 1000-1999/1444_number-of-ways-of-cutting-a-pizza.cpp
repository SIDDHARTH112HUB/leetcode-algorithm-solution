//Link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/ 
class Solution {
public:
    int m = 0;
    int n = 0;
    long long dp[51][51][11];
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int> > apples(m + 1, vector<int>(n + 1));
        for(int i = 0; i < pizza.size(); ++i) {
            for(int j = 0; j < pizza[0].size(); ++j) {
                apples[i + 1][j + 1] = (pizza[i][j] == 'A') + apples[i][j + 1] + apples[i+1][j] - apples[i][j];
            }
        }
        return helper(apples, pizza, 0, 0, k-1);
    }
    
    bool hasApple(vector<vector<int> > &apples, int x, int y, int x1, int y1) {
        return (apples[x1 + 1] [y1 + 1] - apples[x][y1 + 1] -  apples[x1+1][y] + apples[x][y]) > 0;
    }
    long long helper(vector<vector<int> > &apples, vector<string> &pizza, int x, int y, int k) {
        if(k == 0) {
            return hasApple(apples, x, y, m - 1, n - 1);
        }
        if(dp[x][y][k] >= 0) return dp[x][y][k];
        long long res = 0;
        for(int i = x; i < m - 1; ++i) {
            res += helper(apples, pizza, i + 1, y, k - 1) * hasApple(apples, x, y, i, n - 1);
        }
        for(int j = y; j < n - 1; ++j) {
            res += helper(apples, pizza, x, j + 1, k - 1) * hasApple(apples, x, y, m - 1, j);
        }
        res %= 1000000007;
        return dp[x][y][k] = res;
    }
};