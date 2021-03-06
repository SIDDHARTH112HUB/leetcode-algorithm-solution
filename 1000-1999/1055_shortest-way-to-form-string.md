[1055.shortest-way-to-form-string](https://leetcode.com/problems/shortest-way-to-form-string/)  

From any string, we can form a _subsequence_ of that string by deleting some number of characters (possibly no deletions).

Given two strings `source` and `target`, return the minimum number of subsequences of `source` such that their concatenation equals `target`. If the task is impossible, return `-1`.

**Example 1:**

  
**Input:** source = "abc", target = "abcbc"
  
**Output:** 2
  
**Explanation:** The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
  

**Example 2:**

  
**Input:** source = "abc", target = "acdbc"
  
**Output:** \-1
  
**Explanation:** The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
  

**Example 3:**

  
**Input:** source = "xyz", target = "xzyxz"
  
**Output:** 3
  
**Explanation:** The target string can be constructed as follows "xz" + "y" + "xz".
  

**Constraints:**

*   Both the `source` and `target` strings consist of only lowercase English letters from "a"-"z".
*   The lengths of `source` and `target` string are between `1` and `1000`.  



**Solution:**  

```cpp
class Solution {
public:
    int shortestWay(string source, string target) {
        map<int, vector<int> > m;
        for(int i = 0; i < source.size(); ++i) {
            m[source[i]].push_back(i);
        }
        int ans = 1, i = 0, j = 0;
        while(i < target.size()) {
            int c = target[i];
            if(m[c].size() == 0) return -1;
            auto it = lower_bound(m[c].begin(), m[c].end(), j);
            
            if(it == m[c].end()) {
                j = 0;
                ++ans;
            }else{
                ++i;
                j = *it + 1;
            }
        }
        return ans;
    }
};
```
      