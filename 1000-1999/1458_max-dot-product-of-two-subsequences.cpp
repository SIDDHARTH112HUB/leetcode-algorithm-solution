//Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > dp;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return dfs(nums1, nums2, 0, 0);
    }
    
    int dfs(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i >= nums1.size()) return -10000000;
        if(j >= nums2.size()) return -10000000;
        if(dp[i].count(j)) return dp[i][j];
        int ret = dfs(nums1, nums2, i + 1, j+ 1);
        int res = max(nums1[i] * nums2[j], ret + nums1[i] * nums2[j]);
        res = max(res , dfs(nums1, nums2, i, j+ 1));
        res = max(res , dfs(nums1, nums2, i + 1, j));
        return dp[i][j] =res;
    }
};