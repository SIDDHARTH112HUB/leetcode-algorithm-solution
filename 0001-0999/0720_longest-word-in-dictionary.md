[720.longest-word-in-dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)  

Given a list of strings `words` representing an English Dictionary, find the longest word in `words` that can be built one character at a time by other words in `words`. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.

**Example 1:**  

  
**Input:** 
  
words = \["w","wo","wor","worl", "world"\]
  
**Output:** "world"
  
**Explanation:** 
  
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
  

**Example 2:**  

  
**Input:** 
  
words = \["a", "banana", "app", "appl", "ap", "apply", "apple"\]
  
**Output:** "apple"
  
**Explanation:** 
  
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
  

**Note:**

*   All the strings in the input will only contain lowercase letters.
*   The length of `words` will be in the range `[1, 1000]`.
*   The length of `words[i]` will be in the range `[1, 30]`.  



**Solution:**  

```cpp
struct Trie{
    map<char, Trie*> node;
    bool flag;
    Trie(){
        flag = false;
    }
    void build(vector<string> &words){
        
        for( string &str:words){
            auto cur = this;
            //cout<<str<<endl;
            for( char c:str){
                if( !cur->node[c] ){
                    auto n = new Trie();
                    cur->node[c] = n;
                }
                cur  = cur->node[c];
            }
            cur->flag = true;
        }
    }
    void find(Trie* trie,string &ans, string &res){
        if( !trie ) return;
        for( auto it:trie->node){
            if( it.second->flag == true ){
                res += it.first;
                find(it.second, ans, res);
                if( res.size() > ans.size() ) 
                    ans = res;
                res.pop_back();
            }
        }
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        trie.build(words);
        string res, ans;
        trie.find(&trie,ans, res);
        return ans;
    }
    /*
        sort(words.begin(), words.end());
        set<string> dict(words.begin(), words.end());
        string res = "";
        string ans = "";
        queue<string> q;
        q.push("");
        while(q.size() ){
            string &str = q.front();
            for( char i='a'; i<='z'; i++){
                string s1 = str+i;
                if( dict.find(s1) != dict.end() ){
                    q.push(s1);
                    if( s1.size()> ans.size())
                        ans = s1;
                }
            }
            q.pop();
        }
        return ans;
    }*/
};
```
      