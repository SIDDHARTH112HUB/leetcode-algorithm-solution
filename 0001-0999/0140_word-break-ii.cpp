//Link: https://leetcode.com/problems/word-break-ii/ 
class Solution {
public:
    unordered_map<int, vector<int> > m;
    vector<string> ans;
    unordered_set<string> s;
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        for(auto &word: wordDict)
            s.insert(word);
        vector<string> item;
        dfs(str, 0);
        build(str, 0, item);
        return ans;
    }
    void build(string &str, int idx, vector<string> &item){
        if(idx == str.size()){
            string res;
            for(auto &s : item)
                res += s + " ";
            res.pop_back();
            ans.push_back(res);
            return;
        }
        for(auto i : m[idx]) {
            item.push_back(str.substr(idx, i-idx));
            build(str, i, item);
            item.pop_back();
        }
        
    }
    bool dfs(string &str, int idx){
        if(idx >= str.size()) {
            return true;
        }
        if(m.count(idx)) {
            return m[idx].size();
        }
        for(int i = idx; i < str.size(); ++i) {
            auto n = str.substr(idx, i+1 - idx);
            if(s.count(n)){
                bool res = dfs(str, i+1);
                if(res){
                    m[idx].push_back(i+1);
                }
            }
        }
        
        return m[idx].size();
    }
};