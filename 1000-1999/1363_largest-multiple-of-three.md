[1363.largest-multiple-of-three](https://leetcode.com/problems/largest-multiple-of-three/)  

Given an integer array of `digits`, return the largest multiple of **three** that can be formed by concatenating some of the given digits in any order.

Since the answer may not fit in an integer data type, return the answer as a string.

If there is no answer return an empty string.

**Example 1:**

**Input:** digits = \[8,1,9\]
**Output:** "981"

**Example 2:**

**Input:** digits = \[8,6,7,1,0\]
**Output:** "8760"

**Example 3:**

**Input:** digits = \[1\]
**Output:** ""

**Example 4:**

**Input:** digits = \[0,0,0,0,0,0\]
**Output:** "0"

**Constraints:**

*   `1 <= digits.length <= 10^4`
*   `0 <= digits[i] <= 9`
*   The returning answer must not contain unnecessary leading zeros.  



**Solution:**  

```cpp
class Solution {
public:
    string form(vector<int> &cnt) {
        string ans;
        for(int i = 9; i >= 0; --i) {
            for(int j = 0; j < cnt[i]; ++j) {
                ans += i + '0';
            }
        }
        if(ans.size() > 0 && ans[0] == '0') return "0";
        return ans;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> cnt(10);
        for(auto n : digits)
            ++cnt[n];
        int sum = accumulate(digits.begin(), digits.end(), 0);
        if(sum % 3 != 0) {
            for(int i = 1; i <=9; ++i) {
                if(cnt[i] > 0 && i % 3 == sum % 3) {
                    --cnt[i];
                    return form(cnt);
                }
            }
            int x = 3 - (sum % 3);
            int c = 2;
            for(int i = 1; i <= 9; ++i) {
                if(cnt[i] > 0 && i % 3 == x) {
                    int src = cnt[i];
                    cnt[i] -= min(src, c);
                    c -= src;
                    if( c <= 0)
                        return form(cnt);
                }
            }
            return "";
        }
        return form(cnt);
    }
};
```
      