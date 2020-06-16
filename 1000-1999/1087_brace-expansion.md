[1087.brace-expansion](https://leetcode.com/problems/brace-expansion/)  

A string `S` represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, `"{a,b,c}"` represents options `["a", "b", "c"]`.

For example, `"{a,b,c}d{e,f}"` represents the list `["ade", "adf", "bde", "bdf", "cde", "cdf"]`.

Return all words that can be formed in this manner, in lexicographical order.

**Example 1:**

  
**Input:** "{a,b}c{d,e}f"
  
**Output:** \["acdf","acef","bcdf","bcef"\]
  

**Example 2:**

  
**Input:** "abcd"
  
**Output:** \["abcd"\]
  

**Note:**

1.  `1 <= S.length <= 50`
2.  There are no nested curly brackets.
3.  All characters inside a pair of consecutive opening and ending curly brackets are different.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> permute(string S) {
        vector<vector<char> > chars;
        for(int i = 0; i < S.size(); i++) {
            char ch = S[i];
            if(ch == '{'){
                chars.push_back({});
                int j = i+1;
                for(; j<S.size(); j+=2){
                    chars.back().push_back(S[j]);
                    if(S[j+1] == '}'){
                        break;
                    }
                }
                i = j+1;
            }else{
                chars.push_back({ch});
            }
        }
        string str;
        dfs(chars, 0, str);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(vector<vector<char> > chars, int idx, string &str) {
        if(idx == chars.size()){
            ans.push_back(str);
            return;
        }
        for(auto c : chars[idx]){
            str.push_back(c);
            dfs(chars, idx+1, str);
            str.pop_back();
        }
    }
};
```
      