//Link: https://leetcode.com/problems/is-subsequence/ 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        if( s == t) return true;
        int j = 0;
        for(int i = 0; i < t.size(); ++i) {
            if(s[j] == t[i])
                ++j;
            if(j == s.size())
                return true;
        }
        return false;
    }
};