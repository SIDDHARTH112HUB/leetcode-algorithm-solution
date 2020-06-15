[245.shortest-word-distance-iii](https://leetcode.com/problems/shortest-word-distance-iii/)  

Given a list of words and two words _word1_ and _word2_, return the shortest distance between these two words in the list.

_word1_ and _word2_ may be the same and they represent two individual words in the list.

**Example:**  
Assume that words = `["practice", "makes", "perfect", "coding", "makes"]`.

**Input:** _word1_ = `“makes”`, _word2_ = `“coding”`
**Output:** 1

**Input:** _word1_ = `"makes"`, _word2_ = `"makes"`
**Output:** 3

**Note:**  
You may assume _word1_ and _word2_ are both in the list.  



**Solution:**  

```cpp
class Solution {
public:
    map<string, vector<int> > m;
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        for(int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
        int i = 0, j = 0;
        int ans = INT_MAX;
        auto &v1 = m[word1], &v2 = m[word2];
        while(i < v1.size() && j < v2.size()) {
            if(v1[i] == v2[j]) {
                ++i;continue;
            }
            ans = min(ans, abs(v1[i] - v2[j]));
            if(v1[i] > v2[j]) ++j;
            else if(v1[i] < v2[j]) ++i;
        }
        return ans;
    }
};
```
      