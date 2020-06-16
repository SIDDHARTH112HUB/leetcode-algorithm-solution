[208.implement-trie-prefix-tree](https://leetcode.com/problems/implement-trie-prefix-tree/)  

Implement a trie with `insert`, `search`, and `startsWith` methods.

**Example:**

  
Trie trie = new Trie();
  

  
trie.insert("apple");
  
trie.search("apple");   // returns true
  
trie.search("app");     // returns false
  
trie.startsWith("app"); // returns true
  
trie.insert("app");   
  
trie.search("app");     // returns true
  

**Note:**

*   You may assume that all inputs are consist of lowercase letters `a-z`.
*   All inputs are guaranteed to be non-empty strings.  



**Solution:**  

```cpp
class Trie {
    Trie *nodes[26];
    bool is_word;
public:
    /** Initialize your data structure here. */
    Trie() {
        for( int i = 0; i<26; i++)
            this->nodes[i] = NULL;
        is_word = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = this;
        for( char c:word){
            int idx = c-'a';
            if( node->nodes[idx] == NULL){
                node->nodes[idx] = new Trie();
            }
            node = node->nodes[idx];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word, bool prefix= false) {
        auto node = this;
        for( char c : word){
            if( node ){
                node = node->nodes[c-'a'];
            }else
                return false;
        }
        if( node && prefix)
            return true;
        if( node && node->is_word )
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
```
      