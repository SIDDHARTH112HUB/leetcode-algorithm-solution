//Link: https://leetcode.com/problems/tallest-billboard/ 
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for(auto rod : rods) {
            auto cur = dp;
            for(auto it : cur) {
                int diff = it.first;
                int h = it.second;
                dp[rod + diff] = max(dp[rod+diff], h + rod);
                dp[abs(rod - diff)] = max(dp[abs(rod - diff)], h + max(0, rod - diff));
            } 
        }
        return dp[0];
    }
};