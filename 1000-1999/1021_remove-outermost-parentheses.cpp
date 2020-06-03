//Link: https://leetcode.com/problems/remove-outermost-parentheses/ 
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int lv = 0;
        for (char c : S) {
            if (c == '(') {
                if (lv > 0)
                    ans += c;
                ++lv;
            }else{
                --lv;
                if (lv > 0)
                    ans +=c;
                
            }
        }
        return ans;
    }
};