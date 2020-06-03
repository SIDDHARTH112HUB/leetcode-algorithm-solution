//Link: https://leetcode.com/problems/reshape-the-matrix/ 
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        if(m == 0) return nums;
        int n = nums[0].size();
        if(n == 0) return nums;
        if(m * n != r * c) return nums;
        vector<vector<int> > ans(r, vector<int>(c));
        int idx = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ans[idx / c][idx % c] = nums[i][j];
                ++idx;
            }
        }
        return ans;
    }
};