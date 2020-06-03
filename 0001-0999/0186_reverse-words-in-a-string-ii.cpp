//Link: https://leetcode.com/problems/reverse-words-in-a-string-ii/ 
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int j = 0;
        s.push_back(' ');
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }
        s.pop_back();
    }
};