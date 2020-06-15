[320.generalized-abbreviation](https://leetcode.com/problems/generalized-abbreviation/)  

Write a function to generate the generalized abbreviations of a word. 

**Note:** The order of the output does not matter.

**Example:**

**Input:** `"word"`
**Output:**
\["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"\]  



**Solution:**  

```cpp
class Solution {
public:
    /*
    vector<string> generateAbbreviations(string word) {
        if(word.size() == 0) return {""};
        vector<string> ans;
        ans.push_back(to_string(word.size()));
        for(int i = 0; i < word.size(); ++i) {
            for(auto str : generateAbbreviations(word.substr(i + 1))) {
                string l = i == 0 ? "": to_string(i);
                ans.push_back(l + word.substr(i, 1) + str);
            }
        }
        return ans;
    }*/
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        dfs(word, 0, 0, "", ans);
        return ans;
    }
    void dfs(string word, int l, int cnt, string str, vector<string> &ans) {
        if(l >= word.size()) {
            ans.push_back(cnt > 0 ? str += to_string(cnt) : str);
            return;
        }
        dfs(word, l + 1, cnt + 1, str, ans);
        dfs(word, l + 1, 0, str + (cnt > 0 ? to_string(cnt) : "") + word[l], ans);
    }
};
```
      