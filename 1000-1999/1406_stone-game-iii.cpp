//Link: https://leetcode.com/problems/stone-game-iii/ 
class Solution {
public:
    vector<int> dp;
    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size() * 2, INT_MIN);
        int res = h(stoneValue, 0, 1);
        if(res == 0) return "Tie";
        
        return res > 0 ? "Alice" : "Bob";
    }
    
    int h(vector<int>& s, int idx, int sign) {
        if(idx >= s.size()) return 0;
        int ni = (sign == -1 ? idx + s.size() : idx);
        if(dp[ni] != INT_MIN) return dp[ni];
        int res = INT_MIN;
        int sum = 0;
        for(int i = idx; i < min(idx + 3, int(s.size())); ++i) {
            sum += s[i];
            int v = sum - h(s, i + 1, sign * -1);
            res = max(v, res);
        }
        dp[ni] = res;
        return res;
    }
};