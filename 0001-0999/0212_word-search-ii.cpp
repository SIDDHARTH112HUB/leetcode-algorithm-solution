//Link: https://leetcode.com/problems/word-search-ii/ 
struct Trie{
    unordered_map<int, Trie*> m;
    bool isWord = false;
    Trie(){
    }
    
    void insert(string &str) {
        auto node = this;
        for(char c : str) {
            if(!node->m[c])
                node->m[c] = new Trie();
            node = node->m[c];
        }
        node->isWord = true;
    }
    
    Trie* getTrie(int c) {
        return this->m[c];
    }
};
class Solution {
public:
    int m;
    int n;
    unordered_set<int> v;
    unordered_set<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        Trie t;
        for(auto &word : words){
            t.insert(word);
        }
        string item;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n ; ++j){
                dfs(&t, board, i, j, item);
            }
            
        }
        
        return vector<string>(ans.begin(), ans.end());
    }
    
    void dfs(Trie* trie, vector<vector<char>>& board, int x, int y, string &item) {
        
        if (x < 0 || y < 0 || x >= m || y >= n || v.count((x<<16)|y)) return;
        int hash = (x<<16) | y;
        int c = board[x][y];
        auto next = trie->getTrie(c);
        if(!next) return;
        v.insert(hash);
        item.push_back(c);
        if (next->isWord) {
            ans.insert(item);
        }
        dfs(next, board, x+1, y, item);
        dfs(next, board, x, y+1, item);
        dfs(next, board, x, y-1, item);
        dfs(next, board, x-1, y, item);
        item.pop_back();
        v.erase(hash);
    }
};