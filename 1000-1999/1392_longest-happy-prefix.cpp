//Link: https://leetcode.com/problems/longest-happy-prefix/ 
class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size());
        
        for(int i = 1, j = 0; i < s.size(); ++i) {
            while(j > 0 && s[i] != s[j]) j = lps[j-1];
            if(s[i] == s[j]) lps[i] = ++j;
        }
        return s.substr(s.size()-lps.back());
    }
};