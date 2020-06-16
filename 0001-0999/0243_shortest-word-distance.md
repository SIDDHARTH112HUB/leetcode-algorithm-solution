[243.shortest-word-distance](https://leetcode.com/problems/shortest-word-distance/)  

Given a list of words and two words _word1_ and _word2_, return the shortest distance between these two words in the list.

**Example:**  
Assume that words = `["practice", "makes", "perfect", "coding", "makes"]`.

  
**Input:** _word1_ = `“coding”`, _word2_ = `“practice”`
  
**Output:** 3
  

  
**Input:** _word1_ = `"makes"`, _word2_ = `"coding"`
  
**Output:** 1
  

**Note:**  
You may assume that _word1_ **does not equal to** _word2_, and _word1_ and _word2_ are both in the list.  



**Solution:**  

```cpp
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> idx1, idx2;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) idx1.push_back(i);
            else if (words[i] == word2) idx2.push_back(i);
        }
        for (int i = 0; i < idx1.size(); ++i) {
            for (int j = 0; j < idx2.size(); ++j) {
                res = min(res, abs(idx1[i] - idx2[j]));
            }
        }
        return res;
    }
};
```
      