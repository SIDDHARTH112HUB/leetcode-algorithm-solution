[1209.remove-all-adjacent-duplicates-in-string-ii](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)  

Given a string `s`, a _k_ _duplicate removal_ consists of choosing `k` adjacent and equal letters from `s` and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make `k` duplicate removals on `s` until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

**Example 1:**

  
**Input:** s = "abcd", k = 2  
**Output:** "abcd"  
**Explanation:** There's nothing to delete.

**Example 2:**

  
**Input:** s = "deeedbbcccbdaa", k = 3  
**Output:** "aa"  
**Explanation:** First delete "eee" and "ccc", get "ddbbbdaa"  
Then delete "bbb", get "dddaa"  
Finally delete "ddd", get "aa"

**Example 3:**

  
**Input:** s = "pbbcggttciiippooaais", k = 2  
**Output:** "ps"  

**Constraints:**

*   `1 <= s.length <= 10^5`
*   `2 <= k <= 10^4`
*   `s` only contains lower case English letters.  



**Solution:**  

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, int> > stk;
        for(int i = 0; i < s.size(); ++i) {
            if(stk.size() == 0 || stk.back().first != s[i]) {
                stk.push_back({s[i], 1});
            }else{
                ++stk.back().second;
            }
            if(stk.back().second >= k){
                stk.pop_back();
            }
        }
        string ans;
        for(int i = 0; i < stk.size(); ++i) {
            for(int j = 0; j < stk[i].second; ++j) 
                ans += stk[i].first;
        }
        return ans;
    }
};
```
      