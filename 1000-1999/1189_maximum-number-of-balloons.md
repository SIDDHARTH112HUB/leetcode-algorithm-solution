[1189.maximum-number-of-balloons](https://leetcode.com/problems/maximum-number-of-balloons/)  

Given a string `text`, you want to use the characters of `text` to form as many instances of the word **"balloon"** as possible.

You can use each character in `text` **at most once**. Return the maximum number of instances that can be formed.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/09/05/1536_ex1_upd.JPG)**

  
**Input:** text = "nlaebolko"
  
**Output:** 1
  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/09/05/1536_ex2_upd.JPG)**

  
**Input:** text = "loonbalxballpoon"
  
**Output:** 2
  

**Example 3:**

  
**Input:** text = "leetcode"
  
**Output:** 0
  

**Constraints:**

*   `1 <= text.length <= 10^4`
*   `text` consists of lower case English letters only.  



**Solution:**  

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(128);
        for(auto c : text)
            ++cnt[c];
        string s = "balloon";
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'l' || s[i] == 'o') {
                ans = min(ans, cnt[s[i]] / 2);
            }else
                ans = min(ans, cnt[s[i]]);
        }
        return ans;
    }
};
```
      