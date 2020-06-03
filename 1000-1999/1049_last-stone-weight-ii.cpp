//Link: https://leetcode.com/problems/last-stone-weight-ii/ 
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        set<int> s, dp;
        s.insert(0);
        for(auto stone : stones) {
            dp = {};
            for(auto n : s) {
                dp.insert(n - stone);
                dp.insert(n + stone);
            }
            s = dp;
        }
        int ans = INT_MAX;
        for(int n:s)
            ans = min(ans, abs(n));
        return ans;
    }
};