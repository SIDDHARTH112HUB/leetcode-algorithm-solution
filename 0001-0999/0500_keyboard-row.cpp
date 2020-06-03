//Link: https://leetcode.com/problems/keyboard-row/ 
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> m = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        map<int, int> cm;
        for(int i = 0; i < 3; ++i) {
            for(auto c : m[i])
                cm[c] = i;
        }
        vector<string> ans;
        for(auto &w : words) {
            set<int> t;
            for(char c : w) {
                t.insert(cm[c]);
            }
            if(t.size() == 1)
                ans.push_back(w);
        }
        return ans;
    }
};