//Link: https://leetcode.com/problems/encode-string-with-shortest-length/ 
class Solution {
public:
    map<int, map<int, string> > dp;
    string encode(string s) {
        return dfs(s, 0, s.size() - 1);
    }
    
    string dfs(string &s, int l, int r) {
        if(l > r) return "";
        if(r - l < 1) return s.substr(l, r - l + 1);
        if(dp[l].count(r)) return dp[l][r];
        int size = r - l + 1;
        string res = s.substr(l, r - l + 1);
        
        int sq = sqrt(size);
        for(int cnt = 2; cnt <= size; ++cnt) {
            bool f = true;
            if(size % cnt == 0) {
                int len = size / cnt;
                for(int k = 1; k < cnt; ++k) {
                    if(s.substr(l + len * (k - 1), len) != s.substr(l + len * k, len)) {
                        f = false;
                        break;
                    }
                }
                if(f) {
                    string res1 = dfs(s, l, l + len - 1);
                    string ns = to_string(cnt) + '[' + res1 + ']';
                    if(res.size() > ns.size())
                        res = ns;
                }
            }
        }
        for(int i = 1; i < r-l; ++i) {
            auto r1 = dfs(s, l, l + i) + dfs(s, l + i + 1, r);
            if(r1.size() < res.size()) {
                res = r1;
            }
        }
        return dp[l][r] = res;
    }
};