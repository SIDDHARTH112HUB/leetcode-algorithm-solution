[1278.palindrome-partitioning-iii](https://leetcode.com/problems/palindrome-partitioning-iii/)  

You are given a string `s` containing lowercase letters and an integer `k`. You need to :

*   First, change some characters of `s` to other lowercase English letters.
*   Then divide `s` into `k` non-empty disjoint substrings such that each substring is palindrome.

Return the minimal number of characters that you need to change to divide the string.

**Example 1:**

  
**Input:** s = "abc", k = 2
  
**Output:** 1
  
**Explanation:** You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
  

**Example 2:**

  
**Input:** s = "aabbc", k = 3
  
**Output:** 0
  
**Explanation:** You can split the string into "aa", "bb" and "c", all of them are palindrome.

**Example 3:**

  
**Input:** s = "leetcode", k = 8
  
**Output:** 0
  

**Constraints:**

*   `1 <= k <= s.length <= 100`.
*   `s` only contains lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    map<int, map<int, int> > m;
    int palindromePartition(string s, int k) {
        //cout<<"begin"<<endl;
        if(s.size() <= k) return 0;
        return h(s, 0, k);
    }
    int diff(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != s[s.size()-i-1])++ans;
        }
        return ans/2;
    }
    int h(string &s, int idx, int k) {
        if(m[idx].count(k)) return m[idx][k];
        if(k == 1) {
            return diff(s.substr(idx));
        }
        if(idx >= s.size()) {
            if(k == 0) return 0;
            return 100;
            //return 0;
        }
        int res = INT_MAX;
        for(int i = idx+1; i <= s.size(); ++i) {
            int d = diff(s.substr(idx, i-idx));
            //cout<<s.substr(idx, i-idx)<<" "<<d<<endl;
            res = min(res, d + h(s, i, k-1));
        }
        if(res >= 100) res = 100;
        m[idx][k] = res;
        return res;
    }
};
```
      