//Link: https://leetcode.com/problems/perform-string-shifts/ 
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int x = 0;
        for(auto &sf : shift) {
            x += sf[0] == 0 ? -sf[1] : sf[1];
        }
        if(x == 0) return s;
        x = (abs(x) % (int)s.size()) * x / abs(x);
        if(x < 0 ) return s.substr(-x) + s.substr(0, -x);
        return s.substr(s.size() - x) + s.substr(0, s.size() - x);
    }
};