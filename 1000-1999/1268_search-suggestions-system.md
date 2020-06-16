[1268.search-suggestions-system](https://leetcode.com/problems/search-suggestions-system/)  

Given an array of strings `products` and a string `searchWord`. We want to design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return _list of lists_ of the suggested `products` after each character of `searchWord` is typed. 

**Example 1:**

  
**Input:** products = \["mobile","mouse","moneypot","monitor","mousepad"\], searchWord = "mouse"  
**Output:** \[  
\["mobile","moneypot","monitor"\],  
\["mobile","moneypot","monitor"\],  
\["mouse","mousepad"\],  
\["mouse","mousepad"\],  
\["mouse","mousepad"\]  
\]  
**Explanation:** products sorted lexicographically = \["mobile","moneypot","monitor","mouse","mousepad"\]  
After typing m and mo all products match and we show user \["mobile","moneypot","monitor"\]  
After typing mou, mous and mouse the system suggests \["mouse","mousepad"\]  

**Example 2:**

  
**Input:** products = \["havana"\], searchWord = "havana"  
**Output:** \[\["havana"\],\["havana"\],\["havana"\],\["havana"\],\["havana"\],\["havana"\]\]  

**Example 3:**

  
**Input:** products = \["bags","baggage","banner","box","cloths"\], searchWord = "bags"  
**Output:** \[\["baggage","bags","banner"\],\["baggage","bags","banner"\],\["baggage","bags"\],\["bags"\]\]  

**Example 4:**

  
**Input:** products = \["havana"\], searchWord = "tatiana"  
**Output:** \[\[\],\[\],\[\],\[\],\[\],\[\],\[\]\]  

**Constraints:**

*   `1 <= products.length <= 1000`
*   There are no repeated elements in `products`.
*   `1 <= Σ products[i].length <= 2 * 10^4`
*   All characters of `products[i]` are lower-case English letters.
*   `1 <= searchWord.length <= 1000`
*   All characters of `searchWord` are lower-case English letters.  



**Solution:**  

```cpp
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
```
      