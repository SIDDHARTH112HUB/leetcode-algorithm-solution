[424.longest-repeating-character-replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)  

Given a string `s` that consists of only uppercase English letters, you can perform at most `k` operations on that string.

In one operation, you can choose **any** character of the string and change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.

**Note:**  
Both the string's length and _k_ will not exceed 104.

**Example 1:**

  
**Input:**
  
s = "ABAB", k = 2
  

  
**Output:**
  
4
  

  
**Explanation:**
  
Replace the two 'A's with two 'B's or vice versa.
  

**Example 2:**

  
**Input:**
  
s = "AABABBA", k = 1
  

  
**Output:**
  
4
  

  
**Explanation:**
  
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
  
The substring "BBBB" has the longest repeating letters, which is 4.  



**Solution:**  

```cpp

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, j = 0, mx = 0;
        unordered_map<int, int> cnt;
        for(int i = 0; i < s.size(); ++i) {
            mx = max(mx, ++cnt[s[i]]);
            while(i - j + 1 - mx > k) {
                --cnt[s[j++]];
            }
            ans = max(i - j + 1, ans);
        }
        return ans;
    }
};
```
      