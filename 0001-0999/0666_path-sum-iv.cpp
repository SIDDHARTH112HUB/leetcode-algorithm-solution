//Link: https://leetcode.com/problems/path-sum-iv/ 
class Solution {
public:
    unordered_map<int, int> m;
    int ans = 0;
    int pathSum(vector<int>& nums) {
        for(auto n : nums)
            m[n/10] = n % 10;
        dfs(nums[0] / 10, 0);
        return ans;
    }
    
    void dfs(int num, int cur) {
        if(!m.count(num)) return;
        int level = num / 10, pos = num % 10;
        int left = (level + 1) * 10 + 2 * pos - 1;
        int right = left + 1;
        cur += m[num];
        if(!m.count(left) && !m.count(right)) {
            ans += cur;
            return;
        }
        dfs(left, cur);
        dfs(right ,cur);
    }
};