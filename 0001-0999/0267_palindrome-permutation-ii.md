[267.palindrome-permutation-ii](https://leetcode.com/problems/palindrome-permutation-ii/)  

Given a string `s`, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

**Example 1:**

**Input:** `"aabb"`
**Output:** `["abba", "baab"]`

**Example 2:**

**Input:** `"abc"`
**Output:** `[]`  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> ans;
    map<char,int> m;
    char oddChar = 0;
    int len = 0;
    vector<string> generatePalindromes(string s) {
        for(auto c : s) ++m[c];
        int odd = 0;
        for(auto &it : m) {
            odd += it.second % 2;
            if(it.second % 2){
                oddChar = it.first;
                --it.second;
            }
            it.second /= 2;
            len += it.second;
        }
        if(odd > 1) return {};
        string ns;
        dfs(ns);
        return ans;
    }
    
    void dfs(string ns) {
        if(ns.size() == len) {
            ans.push_back(ns + (oddChar ? string(1, oddChar) : "") + string(ns.rbegin(), ns.rend()));
            return;
        }
        for(auto &it : m) {
            if(it.second > 0) {
                --it.second;
                dfs(ns + it.first);
                ++it.second;
            }
        }
    }
};
```
      