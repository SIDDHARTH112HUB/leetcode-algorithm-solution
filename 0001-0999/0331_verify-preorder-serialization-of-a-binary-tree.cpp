//Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/ 
class Solution {
public:
    bool isValidSerialization(string s) {
        int idx = 0;
        return f(s, idx) && idx == s.size();
    }
    
    bool f(string &s, int &idx) {
        if(idx >= s.size()) return false;
        if(s[idx] == '#') {
            idx = min(idx+2, (int)s.size());
            return true;
        }
        while(idx < s.size() && s[idx++] != ',');
        return f(s, idx) && f(s, idx);
    }
};