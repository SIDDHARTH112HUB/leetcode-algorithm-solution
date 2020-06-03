//Link: https://leetcode.com/problems/design-search-autocomplete-system/ 
struct Trie {
    
    unordered_map<char, Trie*> nodes;
    int cnt = 0;
    bool isWord = false;
    void build(string &str, int times) {
        auto node = this;
        for(auto c : str) {
            if(node->nodes[c] == NULL) node->nodes[c] = new Trie();
            node = node->nodes[c];
        }
        node->isWord = true;
        node->cnt -= times;
    }
    
    vector<string> search(string &str, int top) {
        auto node = this;
        int i = 0;
        while(i < str.size() && node->nodes[str[i]])
            node = node->nodes[str[i++]];
        if(i < str.size()) return {};
        vector<pair<int, string> > res;
        node->helper(str, res);
        sort(res.begin(), res.end());
        vector<string> ans;
        for(int i = 0; i < min((int)res.size(), top); ++i) {
            ans.push_back(res[i].second);
        }
        return ans;
    }
    
    void helper(string str, vector<pair<int, string> > &res) {
        auto node = this;
        if(node->isWord) res.push_back({node->cnt, str});
        for(auto it : node->nodes) {
            it.second->helper(str + it.first, res);
        }
    }
};
class AutocompleteSystem {
public:
    Trie trie;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        
        for(int i = 0; i < sentences.size(); ++i) {
            auto &str = sentences[i];
            int t = times[i];
            trie.build(str, t);
        }
    }
    string newStr;
    vector<string> input(char c) {
        if(c == '#') {
            trie.build(newStr, 1);
            newStr = "";
            return {};
        }
        newStr += c;
        return trie.search(newStr, 3);
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */