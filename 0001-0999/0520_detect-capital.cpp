//Link: https://leetcode.com/problems/detect-capital/ 
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1) return true;
        bool l = false, u = false;
        for(int i = 1; i < word.size(); ++i) {
            char c = word[i];
            if(c >='a' && c<='z') {
                l = true;
            }else
                u = true;
        }
        if(word[0] >= 'A' && word[0]<='Z') return !(l && u);
        return l && !u;
    }
};