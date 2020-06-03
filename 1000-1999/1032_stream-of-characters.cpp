//Link: https://leetcode.com/problems/stream-of-characters/ 

struct Trie{
    unordered_map<char, Trie*> nodes;
    bool isWord = false;
    void build(string &str) {
        auto node = this;
        for(auto c : str) {
            auto n = node->nodes[c];
            
            if(!n) n  = new Trie();
            node->nodes[c] = n;
            node = n;
        }
        node->isWord = true;
    }
    bool query(string &str) {
        auto node = this;
        for(int i = str.size() - 1; i >= 0; --i) {
            char c = str[i];
            
            if(node->nodes[c]) {
                node = node->nodes[c];
                if(node->isWord)
                    return true;
            }else
                return false;
        }
        return false;
    }
};
class StreamChecker {
public:
    Trie t;
    string str;
    StreamChecker(vector<string>& words) {
        for(auto &word : words) {
            reverse(word.begin(), word.end());
            t.build(word);
        }
    }
    
    bool query(char letter) {
        str += letter;
        return t.query(str);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */