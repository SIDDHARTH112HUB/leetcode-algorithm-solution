//Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/ 
class Solution {
public:
    int dp[1001][1001];
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return dfs(s1, s2, 0, 0);
    }
    
    int dfs(string &s1, string &s2, int i, int j) {
        if(i == s1.size() ) {
            return accumulate(s2.begin() + j, s2.end(), 0);
        }
        if(j == s2.size()) {
            return accumulate(s1.begin() + i, s1.end(), 0);
        }
        if(dp[i][j] >= 0) return dp[i][j];
        int res = INT_MAX;
        if(s1[i] == s2[j]) {
            res = min(res, dfs(s1, s2, i + 1, j + 1));
        }else {
            res = min(res, s1[i] + dfs(s1, s2, i + 1, j));
            res = min(res, s2[j] + dfs(s1, s2, i, j + 1));
        }
        return dp[i][j] = res;
    }
};
