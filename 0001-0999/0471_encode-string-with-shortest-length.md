[471.encode-string-with-shortest-length](https://leetcode.com/problems/encode-string-with-shortest-length/)  

Given a **non-empty** string, encode the string such that its encoded length is the shortest.

The encoding rule is: `k[encoded_string]`, where the _encoded\_string_ inside the square brackets is being repeated exactly _k_ times.

**Note:**

1.  _k_ will be a positive integer and encoded string will not be empty or have extra space.
2.  You may assume that the input string contains only lowercase English letters. The string's length is at most 160.
3.  If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.

**Example 1:**

  
Input: "aaa"
  
Output: "aaa"
  
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
  

**Example 2:**

  
Input: "aaaaa"
  
Output: "5\[a\]"
  
Explanation: "5\[a\]" is shorter than "aaaaa" by 1 character.
  

**Example 3:**

  
Input: "aaaaaaaaaa"
  
Output: "10\[a\]"
  
Explanation: "a9\[a\]" or "9\[a\]a" are also valid solutions, both of them have the same length = 5, which is the same as "10\[a\]".
  

**Example 4:**

  
Input: "aabcaabcd"
  
Output: "2\[aabc\]d"
  
Explanation: "aabc" occurs twice, so one answer can be "2\[aabc\]d".
  

**Example 5:**

  
Input: "abbbabbbcabbbabbbc"
  
Output: "2\[2\[abbb\]c\]"
  
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2\[abbb\]c", so one answer can be "2\[2\[abbb\]c\]".  



**Solution:**  

```cpp
class Solution {
public:
    map<int, map<int, string> > dp;
    string encode(string s) {
        return dfs(s, 0, s.size() - 1);
    }
    
    string dfs(string &s, int l, int r) {
        if(l > r) return "";
        if(r - l < 1) return s.substr(l, r - l + 1);
        if(dp[l].count(r)) return dp[l][r];
        int size = r - l + 1;
        string res = s.substr(l, r - l + 1);
        
        int sq = sqrt(size);
        for(int cnt = 2; cnt <= size; ++cnt) {
            bool f = true;
            if(size % cnt == 0) {
                int len = size / cnt;
                for(int k = 1; k < cnt; ++k) {
                    if(s.substr(l + len * (k - 1), len) != s.substr(l + len * k, len)) {
                        f = false;
                        break;
                    }
                }
                if(f) {
                    string res1 = dfs(s, l, l + len - 1);
                    string ns = to_string(cnt) + '[' + res1 + ']';
                    if(res.size() > ns.size())
                        res = ns;
                }
            }
        }
        for(int i = 1; i < r-l; ++i) {
            auto r1 = dfs(s, l, l + i) + dfs(s, l + i + 1, r);
            if(r1.size() < res.size()) {
                res = r1;
            }
        }
        return dp[l][r] = res;
    }
};
```
      