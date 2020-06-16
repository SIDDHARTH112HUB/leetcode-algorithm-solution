[318.maximum-product-of-word-lengths](https://leetcode.com/problems/maximum-product-of-word-lengths/)  

Given a string array `words`, find the maximum value of `length(word[i]) * length(word[j])` where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

**Example 1:**

  
**Input:** `["abcw","baz","foo","bar","xtfn","abcdef"]`
  
**Output:** `16 
  
**Explanation:**` The two words can be `"abcw", "xtfn"`.

**Example 2:**

  
**Input:** `["a","ab","abc","d","cd","bcd","abcd"]`
  
**Output:** `4 
  
**Explanation:**` The two words can be `"ab", "cd"`.

**Example 3:**

  
**Input:** `["a","aa","aaa","aaaa"]`
  
**Output:** `0 
  
**Explanation:**` No such pair of words.  



**Solution:**  

```cpp
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> m;
        int ans = 0;
        for(auto &w : words) {
            int n = 0;
            for(auto c : w) 
                n |=  1 << (c - 'a');
            m[n] = max(m[n], (int)w.size());
            for(auto &it : m) {
                if((n & it.first) ==0)
                    ans = max(ans, (int)w.size() * it.second);
            }
        }
        return ans;
    }
};
```
      