[676.implement-magic-dictionary](https://leetcode.com/problems/implement-magic-dictionary/)  

Implement a magic directory with `buildDict`, and `search` methods.

For the method `buildDict`, you'll be given a list of non-repetitive words to build a dictionary.

For the method `search`, you'll be given a word, and judge whether if you modify **exactly** one character into **another** character in this word, the modified word is in the dictionary you just built.

**Example 1:**  

  
Input: buildDict(\["hello", "leetcode"\]), Output: Null
  
Input: search("hello"), Output: False
  
Input: search("hhllo"), Output: True
  
Input: search("hell"), Output: False
  
Input: search("leetcoded"), Output: False
  

**Note:**  

1.  You may assume that all the inputs are consist of lowercase letters `a-z`.
2.  For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
3.  Please remember to **RESET** your class variables declared in class MagicDictionary, as static/class variables are **persisted across multiple test cases**. Please see [here](https://leetcode.com/faq/#different-output) for more details.  



**Solution:**  

```cpp

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_set<string> s;
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto &str : dict)
            s.insert(str);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto &c : word){
            char src = c;
            for(char i = 'a'; i <='z'; ++i) {
                if(i == src) continue;
                c = i;
                if(s.count(word)) return true;
                c = src;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
```
      