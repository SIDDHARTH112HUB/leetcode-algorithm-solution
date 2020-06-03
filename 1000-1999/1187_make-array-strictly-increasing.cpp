//Link: https://leetcode.com/problems/make-array-strictly-increasing/ 
class Solution {
public:
    int dp[2001][2001] = {0};
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int res = dfs(arr1, arr2, 0, 0, INT_MIN);
        return res >= 3000 ? -1 : res;
    }
    
    int dfs(vector<int>& arr1, vector<int>& arr2, int i, int j, int prev) {
        if(i >= arr1.size()) return 0;
        j = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
        if(dp[i][j] > 0) return dp[i][j] - 1;
        int res = 3000;
        if(j < arr2.size())
            res = 1 + dfs(arr1, arr2, i + 1, j, arr2[j] );
        if(arr1[i] > prev)
            res = min(res, dfs(arr1, arr2, i + 1, j, arr1[i]));
        dp[i][j] = res + 1;
        return res;
    }
};