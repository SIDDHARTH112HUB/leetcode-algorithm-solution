//Link: https://leetcode.com/problems/split-array-largest-sum/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > M;
    int splitArray(vector<int>& nums, int m) {
        return solve(nums, 0, m);
    }
    
    int solve(vector<int>& nums, int start, int m) {
        int sum = 0;
        if(m == 1){
            for(int i =  start; i < nums.size(); ++i)
                sum += nums[i];
            return sum;
        }
        if(M[start].count(m)) return M[start][m];
        int ans = INT_MAX;
        for(int i = start; i <= nums.size() - m; ++i) {
            sum += nums[i];
            if(sum > ans)
                break;
            int res = max(sum, solve(nums, i + 1, m - 1));
            ans = min(res, ans);
        }
        M[start][m] = ans;
        return ans;
    }
};