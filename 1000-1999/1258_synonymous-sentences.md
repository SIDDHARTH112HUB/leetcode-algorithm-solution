[1258.synonymous-sentences](https://leetcode.com/problems/synonymous-sentences/)  

Given a list of pairs of equivalent words `synonyms` and a sentence `text`, Return all possible synonymous sentences **sorted lexicographically**.

**Example 1:**

**Input:** synonyms = \[\["happy","joy"\],\["sad","sorrow"\],\["joy","cheerful"\]\],
text = "I am happy today but was sad yesterday"
**Output:** \["I am cheerful today but was sad yesterday",
​​​​​​​"I am cheerful today but was sorrow yesterday",
"I am happy today but was sad yesterday",
"I am happy today but was sorrow yesterday",
"I am joy today but was sad yesterday",
"I am joy today but was sorrow yesterday"\]

**Constraints:**

*   `0 <= synonyms.length <= 10`
*   `synonyms[i].length == 2`
*   `synonyms[0] != synonyms[1]`
*   All words consist of at most `10` English letters only.
*   `text` is a single space separated sentence of at most `10` words.  



**Solution:**  

```cpp
class Solution {
public:
    map<string, string> uf;
    map<string, set<string> > m;
    vector<string> ans;
    string find(string &str) {
        if(uf.count(str)) return uf[str] = (uf[str] == str ? str : find(uf[str]));
        return uf[str] = str;
    }
    void combine(string &a, string &b) {
        auto h1 = find(a);
        auto h2 = find(b);
        if(h1 != h2) 
            uf[h2] = h1;
        uf[h1] = a;
        uf[a] = a;
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        stringstream ss(text);
        vector<string> arr;
        set<string> allwords;
        string token;
        while(getline(ss, token, ' ')) {
            arr.push_back(token);
            allwords.insert(token);
        }
        for(auto &syns : synonyms) {
            allwords.insert(syns[0]);
            for(int i = 1; i < syns.size(); ++i) {
                combine(syns[i], syns[0]);
                allwords.insert(syns[i]);
            }
        }
        for(auto str : allwords) {
            m[find(str)].insert(str);
        }
        vector<string> item;
        h(arr, 0, item);
        return ans;
    }
    
    void h(vector<string> &arr, int idx, vector<string> &item) {
        if(idx >= arr.size()) {
            string str;
            for(auto &s : item){ str += s; str += ' ';}
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for(auto &str: m[find(arr[idx])]) {
            item.push_back(str);
            h(arr, idx+1, item);
            item.pop_back();
        }
    }
};
```
      