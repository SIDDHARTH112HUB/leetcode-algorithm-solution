[1081.smallest-subsequence-of-distinct-characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)  

Return the lexicographically smallest subsequence of `text` that contains all the distinct characters of `text` exactly once.

**Example 1:**

**Input:** "cdadabcc"
**Output:** "adbc"

**Example 2:**

**Input:** "abcd"
**Output:** "abcd"

**Example 3:**

**Input:** "ecbacba"
**Output:** "eacb"

**Example 4:**

**Input:** "leetcode"
**Output:** "letcod"

**Constraints:**

1.  `1 <= text.length <= 1000`
2.  `text` consists of lowercase English letters.

**Note:** This question is the same as 316: [https://leetcode.com/problems/remove-duplicate-letters/](https://leetcode.com/problems/remove-duplicate-letters/)  



**Solution:**  

```cpp
class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> cnt(256), v(256);
        for(char c : text)
            ++cnt[c];
        string ans;
        for(char c : text) {
            --cnt[c];
            if(v[c])
                continue;
            v[c] = 1;
            while(ans.size() && cnt[ans.back()] && c < ans.back()){
                v[ans.back()] = 0;
                ans.pop_back();
            }
            ans += c;
        }
        return ans;
    }
};
```
      