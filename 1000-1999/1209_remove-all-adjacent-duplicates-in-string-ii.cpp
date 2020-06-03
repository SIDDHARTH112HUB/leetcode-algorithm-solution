//Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/ 
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, int> > stk;
        for(int i = 0; i < s.size(); ++i) {
            if(stk.size() == 0 || stk.back().first != s[i]) {
                stk.push_back({s[i], 1});
            }else{
                ++stk.back().second;
            }
            if(stk.back().second >= k){
                stk.pop_back();
            }
        }
        string ans;
        for(int i = 0; i < stk.size(); ++i) {
            for(int j = 0; j < stk[i].second; ++j) 
                ans += stk[i].first;
        }
        return ans;
    }
};