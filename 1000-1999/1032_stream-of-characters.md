[1032.stream-of-characters](https://leetcode.com/problems/stream-of-characters/)  

Implement the `StreamChecker` class as follows:

*   `StreamChecker(words)`: Constructor, init the data structure with the given words.
*   `query(letter)`: returns true if and only if for some `k >= 1`, the last `k` characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.

**Example:**

StreamChecker streamChecker = new StreamChecker(\["cd","f","kl"\]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist

**Note:**

*   `1 <= words.length <= 2000`
*   `1 <= words[i].length <= 2000`
*   Words will only consist of lowercase English letters.
*   Queries will only consist of lowercase English letters.
*   The number of queries is at most 40000.  



**Solution:**  

```cpp

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
```
      