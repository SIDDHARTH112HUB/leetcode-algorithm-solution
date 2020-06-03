//Link: https://leetcode.com/problems/longest-valid-parentheses/ 
class Solution {
public:
    int longestValidParentheses(string s) {
        stack< pair<int, int> > stk;
        stk.push({-1, -1});
        int ans = 0;
        for(int i = 0; i<s.size(); i++ ){
            char c = s[i];
            if( c == '('){
                stk.push({1, i} );
            }else{
                if( stk.size() > 0 && stk.top().first >= 0 ){
                    stk.pop();
                    ans = max( ans, i - stk.top().second);
                }else{
                    stk.push({-1, i});
                }
            }
        }
        return ans;
    }
};