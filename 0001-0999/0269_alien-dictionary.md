[269.alien-dictionary](https://leetcode.com/problems/alien-dictionary/)  

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of **non-empty** words from the dictionary, where **words are sorted lexicographically by the rules of this new language**. Derive the order of letters in this language.

**Example 1:**

**Input:**
\[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
\]

**Output:** `"wertf"`

**Example 2:**

**Input:**
\[
  "z",
  "x"
\]

**Output:** `"zx"`

**Example 3:**

**Input:**
\[
  "z",
  "x",
  "z"
\] 

**Output:** `""` 

**Explanation:** The order is invalid, so return `""`.

**Note:**

*   You may assume all letters are in lowercase.
*   If the order is invalid, return an empty string.
*   There may be multiple valid order of letters, return any one of them is fine.  



**Solution:**  

```cpp
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
     map<int, set<int> > m;
     set<int> v;
     string ans;
     set<int> all;
    string alienOrder(vector<string> &words) {
        // Write your code here
        if(words.size() == 1) return words[0];
        for(int i = 1; i < words.size(); ++i){
            auto &w1 = words[i-1];
            auto &w2 = words[i];
            for(auto c : w1)
                all.insert(c);
            for(auto c : w2)
                all.insert(c);
            if(w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) return "";
            for(int j = 0; j < min(w1.size(), w2.size()); ++j) {
                if(w1[j] == w2[j]) {
                    continue;
                }
                m[w1[j]].insert(w2[j]);
                break;
            }
        }
        for(auto it = all.rbegin(); it != all.rend(); ++it) {
            set<int> v1;
            if(!h(*it, v1)) return "";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool h(char cur, set<int> &v1) {
        if(v1.count(cur)) return false;
        if(v.count(cur)) return true;
        v.insert(cur);
        v1.insert(cur);
        for(auto c : m[cur]) {
            if(!h(c, v1)) return false;
        }
        //cout<<cur<<endl;
        ans += cur;
        return true;
    }
};
```
      