//Link: https://leetcode.com/problems/palindrome-removal/ 
class Solution {
public:
    int dp[101][101];
    int minimumMoves(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return dfs(arr, 0, arr.size() - 1);
    }
    
    int dfs(vector<int>& arr, int l, int r) {
        if(l > r) return 0;
        if(l == r) return 1;
        if(r - l == 1) return (arr[l] != arr[r]) + 1;
        if(dp[l][r] >= 0) return dp[l][r];
        int res = INT_MAX;
        for(int i = l; i <= r; ++i) {
            if(arr[l] == arr[i] && l != i) {
                res = min(res, dfs(arr, l + 1, i - 1) + (i - l < 2 ? 1 :0) + dfs(arr, i + 1, r));
            }else
                res = min(res, dfs(arr, l, i - 1) + 1 + dfs(arr, i+1, r));
        }
        return dp[l][r] = res;
    }
};