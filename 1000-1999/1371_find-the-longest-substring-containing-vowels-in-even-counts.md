[1371.find-the-longest-substring-containing-vowels-in-even-counts](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)  

Given the string `s`, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

**Example 1:**

**Input:** s = "eleetminicoworoep"
**Output:** 13
**Explanation:** The longest substring is "leetminicowor" which contains two each of the vowels: **e**, **i** and **o** and zero of the vowels: **a** and **u**.

**Example 2:**

**Input:** s = "leetcodeisgreat"
**Output:** 5
**Explanation:** The longest substring is "leetc" which contains two e's.

**Example 3:**

**Input:** s = "bcbcbc"
**Output:** 6
**Explanation:** In this case, the given string "bcbcbc" is the longest because all vowels: **a**, **e**, **i**, **o** and **u** appear zero times.

**Constraints:**

*   `1 <= s.length <= 5 x 10^5`
*   `s` contains only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int, int> m, prefix;
        m['a'] = 0;m['i'] = 0;m['e'] = 0;m['o'] = 0;m['u'] = 0;
        prefix[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(m.count(c)){
                sum ^= c;
            }
            if(prefix.count(sum)) {
                ans = max(ans, i - prefix[sum]);
            }else
                prefix[sum] = i;
            
        }
        return ans;
    }
};
```
      