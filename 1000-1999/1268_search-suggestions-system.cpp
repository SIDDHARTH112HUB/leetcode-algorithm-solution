//Link: https://leetcode.com/problems/search-suggestions-system/ 
struct Trie{
    map<char, Trie*> nodes;
    bool isWord = false;
    int cnt = 0;
    void build(string &str) {
        auto node = this;
        for(auto c : str) {
            if(!node->nodes[c])
                node->nodes[c] = new Trie();
            node = node->nodes[c];
        }
        node->isWord = true;
        ++node->cnt;
    }
    void search(string str, vector<string> &res) {
        auto t = this;
        for(auto c : str) {
            if(!t->nodes.count(c))
                return;
            t = t->nodes[c];
        }
        
        if(t->isWord){
            for(int i = 0; i < t->cnt; ++i){
                if(res.size() < 3)
                    res.push_back(str);
            }
        } 
        dfs(t, str, res);
    }
    void dfs(Trie* t, string &str, vector<string> &res) {
        for(auto it : t->nodes) {
            if(res.size() >= 3) return;
            char c = it.first;
            auto next = it.second;
            if(!next) continue;
            str += c;
            if(res.size() >= 3) return;
            if(next->isWord == true) {
                for(int i = 0; i < next->cnt; ++i)
                    if(res.size() < 3)
                        res.push_back(str);
            }
            if(res.size() >= 3) return;
            dfs(next, str, res);
            if(res.size() >= 3) return;
            str.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for(auto p : products) {
            trie.build(p);
        }
        string str;
        vector<vector<string>> ans;
        for(auto &c : searchWord) {
            str+= c;
            vector<string> res;
            trie.search(str, res);
            sort(res.begin(), res.end());
            ans.push_back(res);
        }
        return ans;
    }
};