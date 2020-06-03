//Link: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/ 
class Solution {
public:
    bool isValid(string S) {
        vector<int> v;
        for(int i = 0; i < S.size(); ++i) {
            v.push_back(S[i]);
            if(v.size() >= 3) {
                if(v.back() == 'c' && v[v.size()-2] == 'b' && v[v.size()-3] == 'a') {
                    v.pop_back();
                    v.pop_back();
                    v.pop_back();
                }
            }
        }
        return v.size() == 0;
    }
};