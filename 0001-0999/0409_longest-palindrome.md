[409.longest-palindrome](https://leetcode.com/problems/longest-palindrome/)  

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example `"Aa"` is not considered a palindrome here.

**Note:**  
Assume the length of given string will not exceed 1,010.

**Example:**

  
Input:
  
"abccccdd"
  

  
Output:
  
7
  

  
Explanation:
  
One longest palindrome that can be built is "dccaccd", whose length is 7.  



**Solution:**  

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        map<int, int> m;
        for(auto c : s)
            ++m[c];
        int x = 0, ans = 0;
        for(auto &it : m) {
            x = max(x, it.second % 2);
            ans += it.second / 2 * 2;
        }
        return ans + x;
    }
};
```
      