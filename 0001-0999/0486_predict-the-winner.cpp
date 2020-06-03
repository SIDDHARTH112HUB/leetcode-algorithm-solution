//Link: https://leetcode.com/problems/predict-the-winner/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > m;
    bool PredictTheWinner(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1 ) >= 0;
    }
    
    int dfs(vector<int>& nums, int i, int j) {
        if( i == j) return nums[i];
        if(m[i].count(j)) return m[i][j];
        return m[i][j] = max(nums[i] - dfs(nums, i + 1, j), nums[j] - dfs(nums, i, j-1));
    }
};