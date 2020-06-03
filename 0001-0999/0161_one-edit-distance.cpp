//Link: https://leetcode.com/problems/one-edit-distance/ 
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(abs((int)s.size() - (int)t.size()) > 1) return false;
        if(s == t) return false;
        for(int i = 0; i < min(s.size(), t.size()); ++i) {
            if(s[i] != t[i]) {
                if(s.size() == t.size())
                    return s.substr(i + 1) == t.substr(i + 1);
                int sl = s.size() > t.size();
                return s.substr(i + sl) == t.substr(i + !sl);
            }
        }
        return true;
    }
};