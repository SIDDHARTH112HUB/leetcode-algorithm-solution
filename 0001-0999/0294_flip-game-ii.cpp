//Link: https://leetcode.com/problems/flip-game-ii/ 
class Solution {
public:
    map<string, bool> dp;
    bool canWin(string &s) {
        if(s.size() < 1) return false;
        if(s.size() == 2) return s[0] == '+' && s[1] == '+' ? true : false;
        if(dp.count(s)) return dp[s];
        bool res = false;
        for(int i = 0; i < s.size()-1; ++i) {
            if(s[i] == '+' && s[i+1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                res = !canWin(s);
                s[i] = '+';
                s[i+1] = '+';
                if(res)
                    return dp[s] = res;
            }
        }
        return dp[s] = false;
    }
    
    bool dfs(string s) {
        if(s.size() < 2) return false;
        if(s.size() == 2) return s[0] == '+' && s[1] == '+' ? true : false;
        if(dp.count(s)) return dp[s];
        int res = false;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == '+' && s[i+1] == '+') {
                res = !dfs(s.substr(0, i ) + "-" + s.substr(i + 2));
                if(res == true)
                    break;
            }
        }
        return dp[s] = res;
    }
};