//Link: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/ 
class Solution {
public:
    unordered_map<int, string> dp;
    
    string largestNumber(vector<int>& cost, int target) {
        string ans = dfs(cost, target);
        return ans == "" ? "0" : ans;
    }
    
    string dfs(vector<int>& cost, int target) {
        if(target == 0) return "";
        if(dp.count(target)) return dp[target];
        string ans;
        for(int i = 0; i < cost.size(); ++i) {
            int cs = cost[i];
            if(target >= cs) {
                auto ns = string(1, i + 1 + '0') + dfs(cost, target - cs);
                if(ns.back() == '0') continue;
                if(ans.size() == 0 || ans.size() < ns.size() || (ans.size() == ns.size() && ans < ns))
                    ans = ns;
            }
        }
        return dp[target] = ans == "" ? "0" : ans;
    }
};