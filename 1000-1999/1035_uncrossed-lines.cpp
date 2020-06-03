//Link: https://leetcode.com/problems/uncrossed-lines/ 
class Solution {
public:
    int dp[500][500];
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(dp, -1, sizeof(dp));
        return dfs(A, B, 0, 0);
        for(int i = 0; i < A.size(); ++i) 
            for(int j = 0; j < B.size(); ++j) 
                if(A[i] == B[j]) dp[i][j] = max(dp[i][j], (i > 0 && j > 0 ? dp[i-1][j-1] : 0) + 1);
                else dp[i][j] = max(j > 0 ? dp[i][j-1]:0, i > 0 ? dp[i-1][j] : 0);
        return dp[A.size()-1][B.size()-1];
    }
    
    int dfs(vector<int>& A, vector<int>& B, int i, int j) {
        if(A.size() <= i) return 0;
        if(B.size() <= j) return 0;
        if(dp[i][j] >= 0) return dp[i][j];
        return dp[i][j] = A[i] == B[j] ? (1 + dfs(A, B, i + 1, j + 1)) : max(dfs(A, B, i + 1, j), dfs(A, B, i, j + 1));
    }
};