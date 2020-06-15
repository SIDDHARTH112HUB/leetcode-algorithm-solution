[890.find-and-replace-pattern](https://leetcode.com/problems/find-and-replace-pattern/)  

You have a list of `words` and a `pattern`, and you want to know which words in `words` matches the pattern.

A word matches the pattern if there exists a permutation of letters `p` so that after replacing every letter `x` in the pattern with `p(x)`, we get the desired word.

(_Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter._)

Return a list of the words in `words` that match the given pattern. 

You may return the answer in any order.

**Example 1:**

**Input:** words = \["abc","deq","mee","aqq","dkd","ccc"\], pattern = "abb"
**Output:** \["mee","aqq"\]
**Explanation:** "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.

**Note:**

*   `1 <= words.length <= 50`
*   `1 <= pattern.length = words[i].length <= 20`  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for( auto &word: words){
            unordered_map<int, int> m1,m2;
            bool flag = true;
            for( int i = 0; i<word.size(); i++){
                char wc = word[i], pc = pattern[i];
                if( m1[wc] == 0 && m2[pc] == 0 ){
                    m1[wc] = pc;
                    m2[pc] = wc;
                }else if( m1[wc] != pc || m2[pc] != wc){
                    flag = false;
                    break;
                }
            }
            if( flag )
                ans.push_back(word);
        }
        return ans;
    }
};
```
      