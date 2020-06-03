//Link: https://leetcode.com/problems/remove-palindromic-subsequences/ 
class Solution {
public:
    map<int, map<int, int> > m;
    int removePalindromeSub(string s) {
        if(s.size() == 0) return 0;
        string a = s;
        reverse(a.begin(), a.end());
        if(s == a) return 1;
        return 2;
    }
};