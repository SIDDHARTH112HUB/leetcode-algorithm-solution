[522.longest-uncommon-subsequence-ii](https://leetcode.com/problems/longest-uncommon-subsequence-ii/)  

Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be **any** subsequence of the other strings.

A **subsequence** is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

**Example 1:**  

  
**Input:** "aba", "cdc", "eae"
  
**Output:** 3
  

**Note:**

1.  All the given strings' lengths will not exceed 10.
2.  The length of the given list will be in the range of \[2, 50\].  



**Solution:**  

```cpp
class Solution {
public:
    int h(string &s1, string &s2) {
        int i = 0, j = 0;
        for(; i < s2.size() && j < s1.size(); ++j) {
            if(s2[i] == s1[j])
                ++i;
        }
        return i == s2.size();
    }
    int findLUSlength(vector<string> &strs) {
        // write your code here
        sort(strs.begin(), strs.end(), [](auto &s1, auto &s2){
            if(s1.size() == s2.size()) {
                return s1 < s2;
            }
            return s1.size() > s2.size();
        });
        int i = 1;
        for(int i = 0; i < strs.size(); ++i) {
            int flag = false;
            for(int j = 0; j < strs.size(); ++j) {
                if(i == j) continue;
                flag = flag || h(strs[j], strs[i]);
                if(flag) break; 
            }
            if(!flag) return strs[i].size();
        }
        return -1;
    }
};
```
      