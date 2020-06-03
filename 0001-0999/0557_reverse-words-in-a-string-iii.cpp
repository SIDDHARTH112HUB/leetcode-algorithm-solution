//Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/ 
class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0, j = 0; i <= s.size(); ++i) {
            if(i < s.size() && s[i] !=' ') continue;
            reverse(s.begin() + j, s.begin() + i);
            j = i + 1;
        }
        return s;
    }
};