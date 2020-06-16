[1316.distinct-echo-substrings](https://leetcode.com/problems/distinct-echo-substrings/)  

Return the number of **distinct** non-empty substrings of `text` that can be written as the concatenation of some string with itself (i.e. it can be written as `a + a` where `a` is some string).

**Example 1:**

  
**Input:** text = "abcabcabc"  
**Output:** 3  
**Explanation:** The 3 substrings are "abcabc", "bcabca" and "cabcab".  

**Example 2:**

  
**Input:** text = "leetcodeleetcode"  
**Output:** 2  
**Explanation:** The 2 substrings are "ee" and "leetcodeleetcode".  

**Constraints:**

*   `1 <= text.length <= 2000`
*   `text` has only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int ans = 0;
    int distinctEchoSubstrings(string text) {
        int res = 0;
        unordered_set<string> ans;
        for(int i = 1; i <= text.size()/2; ++i) {
            for(int j = 0; j <= text.size() - i; ++j) {
                auto str = text.substr(j, i);
                auto str1 = text.substr(j + i, i);
                if(ans.count(str)) continue;
                if(str.size() != str1.size()) break;
                if(str == str1){
                    ans.insert(str);
                    ++res;
                }
            }
        }
        return res;
    }
};
```
      