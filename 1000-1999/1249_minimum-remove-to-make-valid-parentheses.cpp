//Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/ 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<pair<int, int> > stk;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] >= 'a' && s[i] <= 'z') continue;
            if(s[i] == '(' || stk.size() == 0) {
                stk.push_back({s[i], i});
            }else {
                if(stk.back().first == '(') {
                    stk.pop_back();
                }else {
                    stk.push_back({s[i], i});
                }
            }
        }
        int j = 0;
        string ans;
        for(int i = 0; i < s.size(); ++i) {
            if(j < stk.size() && stk[j].second == i) {
                ++j;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};