//Link: https://leetcode.com/problems/split-a-string-in-balanced-strings/ 
class Solution {
public:
    int balancedStringSplit(string s) {
        stack<int> stk;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(stk.size() == 0) {
                stk.push(s[i]);
            }else{
                if(stk.top() != s[i])
                    stk.pop();
                else
                    stk.push(s[i]);
                if(stk.size() == 0)
                    ++ans;
            }
        }
        return ans;
    }
};