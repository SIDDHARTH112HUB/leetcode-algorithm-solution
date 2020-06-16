[1178.number-of-valid-words-for-each-puzzle](https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/)  

With respect to a given `puzzle` string, a `word` is _valid_ if both the following conditions are satisfied:

*   `word` contains the first letter of `puzzle`.
*   For each letter in `word`, that letter is in `puzzle`.  
    For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; while invalid words are "beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle).

Return an array `answer`, where `answer[i]` is the number of words in the given word list `words` that are valid with respect to the puzzle `puzzles[i]`.

**Example :**

  
**Input:**   
words = \["aaaa","asas","able","ability","actt","actor","access"\],   
puzzles = \["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"\]  
**Output:** \[1,1,3,2,4,0\]  
**Explanation:**  
1 valid word for "aboveyz" : "aaaa"   
1 valid word for "abrodyz" : "aaaa"  
3 valid words for "abslute" : "aaaa", "asas", "able"  
2 valid words for "absoryz" : "aaaa", "asas"  
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"  
There're no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.  

**Constraints:**

*   `1 <= words.length <= 10^5`
*   `4 <= words[i].length <= 50`
*   `1 <= puzzles.length <= 10^4`
*   `puzzles[i].length == 7`
*   `words[i][j]`, `puzzles[i][j]` are English lowercase letters.
*   Each `puzzles[i]` doesn't contain repeated characters.  



**Solution:**  

```cpp
typedef long long ll;
class Solution {
public:
    unordered_map<int, int> wordMap;
    void f(vector<string> &words, unordered_map<int, int>  &m) {
        for(int i = 0; i < words.size(); ++i) {
            auto &word = words[i];
            int mask = 0;
            for(auto c : word)
                mask |= 1 << (c-'a');
            ++m[mask];
        }
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        f(words, wordMap);
        vector<int> ans(puzzles.size());
        for(int i = 0; i < puzzles.size(); ++i) {
            auto &str = puzzles[i];
            for(int j = 0; j < (1 << (str.size() - 1)); ++j) {
                int mask = (1 << (str[0] - 'a'));
                for(int k = 1; k < str.size(); ++k) {
                    if( (j >> (k-1) ) & 1)
                        mask |= (1 << (str[k] - 'a'));
                }
                ans[i] += wordMap[mask];
            }
        }
        return ans;
    }
};
```
      