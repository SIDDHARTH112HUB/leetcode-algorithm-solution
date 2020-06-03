//Link: https://leetcode.com/problems/generalized-abbreviation/ 
class Solution {
public:
    /*
    vector<string> generateAbbreviations(string word) {
        if(word.size() == 0) return {""};
        vector<string> ans;
        ans.push_back(to_string(word.size()));
        for(int i = 0; i < word.size(); ++i) {
            for(auto str : generateAbbreviations(word.substr(i + 1))) {
                string l = i == 0 ? "": to_string(i);
                ans.push_back(l + word.substr(i, 1) + str);
            }
        }
        return ans;
    }*/
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        dfs(word, 0, 0, "", ans);
        return ans;
    }
    void dfs(string word, int l, int cnt, string str, vector<string> &ans) {
        if(l >= word.size()) {
            ans.push_back(cnt > 0 ? str += to_string(cnt) : str);
            return;
        }
        dfs(word, l + 1, cnt + 1, str, ans);
        dfs(word, l + 1, 0, str + (cnt > 0 ? to_string(cnt) : "") + word[l], ans);
    }
};