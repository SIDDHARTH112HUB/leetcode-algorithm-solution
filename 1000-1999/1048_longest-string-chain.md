[1048.longest-string-chain](https://leetcode.com/problems/longest-string-chain/)  

Given a list of words, each word consists of English lowercase letters.

Let's say `word1` is a predecessor of `word2` if and only if we can add exactly one letter anywhere in `word1` to make it equal to `word2`.  For example, `"abc"` is a predecessor of `"abac"`.

A _word chain_ is a sequence of words `[word_1, word_2, ..., word_k]` with `k >= 1`, where `word_1` is a predecessor of `word_2`, `word_2` is a predecessor of `word_3`, and so on.

Return the longest possible length of a word chain with words chosen from the given list of `words`.

**Example 1:**

**Input:** \["a","b","ba","bca","bda","bdca"\]
**Output:** 4
**Explanation**: one of the longest word chain is "a","ba","bda","bdca".

**Note:**

1.  `1 <= words.length <= 1000`
2.  `1 <= words[i].length <= 16`
3.  `words[i]` only consists of English lowercase letters.  



**Solution:**  

```cpp
class Solution {
public:
    int longestStrChain(vector<string>& _words) {
        unordered_set<string> words(_words.begin(), _words.end());
        vector<unordered_map<string, int> > m(16);
        for(auto &s : words){
            m[s.size() - 1][s] = 1;
        }
        int ans = 1;
        for(int i = 1; i < 16; ++i) {
            for(auto &it : m[i]){
                auto &str = it.first;
                auto &cnt = it.second;
                for(int j = 0; j < str.size(); ++j){
                    string ns = str.substr(0, j) + str.substr(j+1);
                    if(words.count(ns)){
                        cnt = max(cnt, m[i-1][ns]+1);
                        ans = max(ans, cnt);
                    }
                }
            }
        }
        return ans;
    }
};
```
      