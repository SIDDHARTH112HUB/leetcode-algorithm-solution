[211.add-and-search-word-data-structure-design](https://leetcode.com/problems/add-and-search-word-data-structure-design/)  

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters `a-z` or `.`. A `.` means it can represent any one letter.

**Example:**

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

**Note:**  
You may assume that all words are consist of lowercase letters `a-z`.  



**Solution:**  

```cpp
struct Trie{
    Trie *nodes[26];
    int weight;
    Trie(){
        weight = -1;
        memset(nodes, 0, sizeof(nodes));
    }
    void insert(string &s, int weight=0){
        auto node = this;
        for( int i = 0; i<s.size(); i++){
            int c = s[i]-'a';
            if( node->nodes[c] == NULL ){
                node->nodes[c] = new Trie();
            }
            node = node->nodes[c];
        }
        node->weight = weight;
    }
    
    bool search(string &s){
        Trie *preT = this;
        for( int i = 0; i<s.size(); i++){
            if( s[i] == '.' ){
                string str = s.substr(i+1);
                for( int j = 0; j<26; j++){
                    if( preT->nodes[j]){
                        bool res = preT->nodes[j]->search(str);
                        if( res == true )
                            return true;
                    }
                }
                return false;
            }else{
                char c = s[i]-'a';
                preT = preT->nodes[c];
                if( preT == NULL )
                    return false;
            }
        }
        return preT->weight >= 0;
    }
};

class WordDictionary {
public:
    Trie *trie;
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie->search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
```
      