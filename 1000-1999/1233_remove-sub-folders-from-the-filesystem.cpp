//Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/ 
struct Trie{
    unordered_map<string, Trie*> nodes;
    bool isWord = false;
    void build(string &word) {
        auto node = this;
        for(int i = 1; i < word.size(); ++i) {
            string str;
            while(i < word.size() && word[i] != '/')
                str += word[i++];
            //cout<<str<<endl;
            auto next = node->nodes[str];
            if(!next) next = new Trie();
            node->nodes[str] = next;
            node = next;
        }
        node->isWord = true;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie t;
        for(auto &f : folder)
            t.build(f);
        string fol = "/";
        dfs(&t, fol);
        return ans;
    }
    
    void dfs(Trie *t, string &folder) {
        //folder += '/';
        if(t->isWord ==true) {
            folder.pop_back();
            ans.push_back(folder);
            folder += '/';
            return;
        }
        for(auto &it : t->nodes){
            auto c = it.first;
            auto next = it.second;
            folder += c;
            folder += '/';
            dfs(next, folder);
            folder.pop_back();
            while(folder.size() && folder.back() !='/') folder.pop_back();
        }
        //folder.pop_back();
    }
};