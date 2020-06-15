[244.shortest-word-distance-ii](https://leetcode.com/problems/shortest-word-distance-ii/)  

Design a class which receives a list of words in the constructor, and implements a method that takes two words _word1_ and _word2_ and return the shortest distance between these two words in the list. Your method will be called _repeatedly_ many times with different parameters. 

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
class WordDistance {
public:
    map<string, vector<int> > m;
    WordDistance(vector<string>& words) {
        int i = 0;
        for(auto &w : words) {
            m[w].push_back(i++);
        }
    }
    
    int shortest(string w1, string w2) {
        auto &v2 = m[w2];
        int res = INT_MAX;
        for(auto idx : m[w1]) {
            //auto l = lower_bound(v2.begin(), v2.end(), idx);
            auto r = upper_bound(v2.begin(), v2.end(), idx);
            auto l = r;
            if(l != v2.begin()) --l;
            res = min(res, abs(*l - idx));
            if(r == v2.end()) --r;
            res = min(res, abs(*r - idx));
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
```
      