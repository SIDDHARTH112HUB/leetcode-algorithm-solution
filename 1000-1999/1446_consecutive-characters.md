[1446.consecutive-characters](https://leetcode.com/problems/consecutive-characters/)  

Given a string `s`, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return _the power_ of the string.

**Example 1:**

  
**Input:** s = "leetcode"
  
**Output:** 2
  
**Explanation:** The substring "ee" is of length 2 with the character 'e' only.
  

**Example 2:**

  
**Input:** s = "abbcccddddeeeeedcba"
  
**Output:** 5
  
**Explanation:** The substring "eeeee" is of length 5 with the character 'e' only.
  

**Example 3:**

  
**Input:** s = "triplepillooooow"
  
**Output:** 5
  

**Example 4:**

  
**Input:** s = "hooraaaaaaaaaaay"
  
**Output:** 11
  

**Example 5:**

  
**Input:** s = "tourist"
  
**Output:** 1
  

**Constraints:**

*   `1 <= s.length <= 500`
*   `s` contains only lowercase English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            bool f = true;
            for(int j = i; j < s.size(); ++j ){
                if(s[j] != s[i]) {
                    f = false;
                    break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
```
      