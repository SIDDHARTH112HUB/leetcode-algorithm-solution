//Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/ 
class Solution {
public:
    string reverseParentheses(string s) {
        int idx = 0;
        dfs(s, idx);
        string ans;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != '(' && s[i] != ')')
                ans += s[i];
        }
        return ans;
    }
    
    void dfs(string &s, int &idx) {
        while(idx < s.size()){
            if(s[idx] == '(') {
                int src = ++idx;
                dfs(s, idx);
                reverse(s.begin() + src, s.begin() + idx);
            }else if(s[idx] == ')'){
                ++idx;
                return;
            }else
                ++idx;
        }
    }
};