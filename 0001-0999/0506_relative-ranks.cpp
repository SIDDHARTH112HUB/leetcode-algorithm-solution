//Link: https://leetcode.com/problems/relative-ranks/ 
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
            m[nums[i]] = i;
        vector<string> ans(nums.size());
        int idx = 0;
        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for(auto it = m.rbegin(); it != m.rend(); ++it) {
            int i = it->second;
            ans[i] = idx >= rank.size() ? to_string(idx+1):rank[idx];
            ++idx;
        }
        return ans;
    }
};