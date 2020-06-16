[745.prefix-and-suffix-search](https://leetcode.com/problems/prefix-and-suffix-search/)  

Given many `words`, `words[i]` has weight `i`.

Design a class `WordFilter` that supports one function, `WordFilter.f(String prefix, String suffix)`. It will return the word with given `prefix` and `suffix` with maximum weight. If no word exists, return -1.

**Examples:**

  
**Input:**
  
WordFilter(\["apple"\])
  
WordFilter.f("a", "e") // returns 0
  
WordFilter.f("b", "") // returns -1
  

**Note:**

1.  `words` has length in range `[1, 15000]`.
2.  For each test case, up to `words.length` queries `WordFilter.f` may be made.
3.  `words[i]` has length in range `[1, 10]`.
4.  `prefix, suffix` have lengths in range `[0, 10]`.
5.  `words[i]` and `prefix, suffix` queries consist of lowercase letters only.  



**Solution:**  

```cpp
struct Trie{
    Trie *nodes[26];
    int weight;
    Trie(){
        weight = -1;
        memset(nodes, 0, sizeof(nodes));
    }
    void insert(string &s, int weight){
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
    
    Trie* getTrie(string &s){
        Trie *preT = this;
        for( int i = 0; i<s.size(); i++){
            char c = s[i]-'a';
            preT = preT->nodes[c];
            if( preT == NULL )
                return NULL;
        }
        return preT;
    }
    int get_weight(string &pre, set<int> &s){
        auto preT = this->getTrie(pre);
        if( preT == NULL )
            return -1;
        int ans = 0;
        helper(preT, s);
        return ans;
    }
    
    void helper(Trie *t, set<int> &s){
        if( t->weight >= 0 ){
            s.insert(t->weight);
        }
        for( int i = 0; i<26; i++){
            if( t->nodes[i] ){
                helper(t->nodes[i], s);
            }
        }
    }
};

class WordFilter {
public:
    Trie *preT;
    Trie *sufT;
    WordFilter(vector<string> words) {
        preT = new Trie();
        sufT = new Trie();
        for( int i = 0; i<words.size(); i++ ){
            auto &s = words[i];
            preT->insert(s, i);
            reverse(s.begin(), s.end());
            //cout<<s<<endl;
            sufT->insert(s, i);
        }
    }
    
    int f(string prefix, string suffix) {
        set<int> s1,s2;
        reverse(suffix.begin(), suffix.end());
        preT->get_weight(prefix, s1);
        sufT->get_weight(suffix, s2);
        if( s1.size() == 0 || s2.size() == 0 )
            return -1;
        int ans = 0;
        for( auto n:s1){
            if( s2.count(n) )
                ans = max(n,ans);
        }
        return ans;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
```
      