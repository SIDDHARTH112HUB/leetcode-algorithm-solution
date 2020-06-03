//Link: https://leetcode.com/problems/word-squares/ 
// struct Trie {
//     Trie* nodes[128];
//     bool isWord = false;
//     void build(string s) {
//         auto node = this;
//         for(int i = 0; i < s.size(); ++i) {
//             char c = s[i];
//             if(!node->nodes[c]) node->nodes[c] = new Trie();
//             node = node->nodes[c];
//         }
//         node->isWord = true;
//     }
    
    
// };
// class Solution {
// public:
//     Trie trie;
//     vector<vector<string> > ans;
//     unordered_set<string> vis;
//     vector<vector<string>> wordSquares(vector<string>& words) {
//         for(auto str : words){
//             if(str.size() == 0) continue;
//             trie.build(str);
//         }
//         vector<Trie*> tries(words[0].size(), &trie);
//         vector<string> item;
//         dfs(words, tries, item);
//         return ans;
//     }
    
//     void dfs(vector<string> &v, vector<Trie*> &tries, vector<string> &item) {
//         if(item.size() > 0 && item[0].size() == item.size()) {
//             ans.push_back(item);
//             return;
//         }
//         for(int i = 0; i < v.size(); ++i){
//             string &s = v[i];
//             // cout<<s<<endl;
//             // if(vis.count(s)) continue;
//             auto nt = tries;
//             bool f = true;
//             for(int j = 0; j < s.size(); ++j) {
//                 if(!tries[j]->nodes[s[j]]) {
//                     f = false;
//                     break;
//                 }
//                 nt[j] = tries[j]->nodes[s[j]];
//                 if(j < item.size()) {
//                     if(item[j][item.size()] != s[j]) {
//                         f = false;
//                         break;
//                     }
//                 }
//             }
//             if(f) {
//                 item.push_back(s);
//                 dfs(v, nt, item);
//                 item.pop_back();
//             }else{
//                 // cout<<item.size()<<" "<<s<<endl;
//             }
//         }
//     }
// };

class Solution {
public:
    struct TrieNode {
        vector<int> indexs;
        vector<TrieNode*> children;
        TrieNode(): children(26, nullptr) {}
    };
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *t = root;
            for (int j = 0; j < words[i].size(); ++j) {
                if (!t->children[words[i][j] - 'a']) {
                    t->children[words[i][j] - 'a'] = new TrieNode();
                }
                t = t->children[words[i][j] - 'a'];
                t->indexs.push_back(i);
            }
        }
        return root;
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> out(words[0].size());
        vector<vector<string>> res;
        for (string word : words) {
            out[0] = word;
            helper(words, 1, root, out, res);
        }
        return res;
    }
    void helper(vector<string>& words, int level, TrieNode* root, vector<string>& out, vector<vector<string>>& res) {
        if (level >= words[0].size()) {
            res.push_back(out);
            return;
        }
        string str = "";
        for (int i = 0; i < level; ++i) {
            str += out[i][level];
        }
        TrieNode *t = root;
        for (int i = 0; i < str.size(); ++i) {
            if (!t->children[str[i] - 'a']) return;
            t = t->children[str[i] - 'a'];
        }
        for (int idx : t->indexs) {
            out[level] = words[idx];
            helper(words, level + 1, root, out, res);
        }
    }
};