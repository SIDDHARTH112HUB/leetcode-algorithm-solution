//Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ 
class Solution {
public:
    map<int, map<int, int> > m;
    int minInsertions(string s) {
        return helper(s, 0, s.size() - 1);
    }
    
    int helper(string &s, int l, int r) {
        if(r == l ) return 0;
        if( l > r) return 0;
        if(r - l == 1) return s[l] == s[r] ? 0 : 1;
        if(m[l].count(r)) return m[l][r];
        if(s[l] == s[r]) {
            return helper(s, l + 1, r - 1 );
        }
        int res = min(1 + helper(s, l + 1, r), 1 + helper(s, l, r-1));
        m[l][r] = res;
        return res;
    }
};