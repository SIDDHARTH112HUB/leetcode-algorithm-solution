//Link: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/ 
class Solution {
public:
    map<char, pair<int, int> > co;
    map<int, map<int, map<int, int> > > dp;
    int minimumDistance(string word) {
        vector<string> mp = {"ABCDEF", "GHIJKL", "MNOPQR", "STUVWX", "YZ"};
        
        for(int i = 0; i < mp.size(); ++i) {
            for(int j = 0; j < mp[i].size(); ++j) {
                co[mp[i][j]] = {i, j};
            }
        }
        return h(word, 1, word[0], -1);
    }
    
    int dis(char a, char b) {
        return abs(co[a].first - co[b].first) + abs(co[a].second - co[b].second);
    }
    
    int h(string &s, int idx, int l, int r) {
        if(idx >= s.size()) return 0;
        if(dp[idx][l].count(r)) return dp[idx][l][r];
        char c = s[idx];
        int step = h(s, idx + 1, c, r) + dis(c, l);
        if(r == -1)
            step = min(h(s, idx + 1, l, c ), step);
        else
            step = min(step, h(s, idx+1, l, c) + dis(c, r));
        dp[idx][l][r] = step;
        return step;
    }
};