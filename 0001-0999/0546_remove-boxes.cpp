//Link: https://leetcode.com/problems/remove-boxes/ 
class Solution {
public:
    
    int removeBoxes(vector<int>& boxes) {
        if(boxes.size() == 0) return 0;
        int dp[100][100][100];
        memset(dp, 0, sizeof(dp));
        return dfs(boxes, 0, boxes.size()-1, 0, dp);
    }
    
    int dfs(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
        if(i > j) return 0;
        if(dp[i][j][k]) return dp[i][j][k];
        int res = (1+k) * (1+k) + dfs(boxes, i+1, j, 0, dp);
        for(int m = i+1; m <=j; ++m) {
            if(boxes[i] == boxes[m]) {
                res = max(res, dfs(boxes, i+1, m-1, 0, dp) + dfs(boxes, m, j, k+1, dp));
            }
        }
        dp[i][j][k] = res;
        return res;
    }
};