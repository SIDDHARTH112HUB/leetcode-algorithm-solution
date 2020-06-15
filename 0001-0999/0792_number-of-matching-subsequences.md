[792.number-of-matching-subsequences](https://leetcode.com/problems/number-of-matching-subsequences/)  

Given string `S` and a dictionary of words `words`, find the number of `words[i]` that is a subsequence of `S`.

**Example :**
**Input:** 
S = "abcde"
words = \["a", "bb", "acd", "ace"\]
**Output:** 3
**Explanation:** There are three words in `words` that are a subsequence of `S`: "a", "acd", "ace".

**Note:**

*   All words in `words` and `S` will only consists of lowercase letters.
*   The length of `S` will be in the range of `[1, 50000]`.
*   The length of `words` will be in the range of `[1, 5000]`.
*   The length of `words[i]` will be in the range of `[1, 50]`.  



**Solution:**  

```cpp
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<int> > m;
        int ans = 0, i = 0;
        for( char c:S){
            m[c].push_back(i++);
        }
        for( auto &word: words){
            int cur = 0;
            int found = true;
            for(auto c : word) {
                auto &m2 = m[c];
                int idx = lower_bound(m2.begin(), m2.end(), cur) - m2.begin();
                if(idx >= m2.size()) {
                    found = false;
                    break;
                }
                cur = m2[idx] + 1;
            }
            if(found)
                ++ans;
        }
        return ans;
    }
};
```
      