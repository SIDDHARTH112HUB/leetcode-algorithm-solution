[1542.find-longest-awesome-substring](https://leetcode.com/problems/find-longest-awesome-substring/)  

Given a string `s`. An _awesome_ substring is a non-empty substring of `s` such that we can make any number of swaps in order to make it palindrome.

Return the length of the maximum length **awesome substring** of `s`.

**Example 1:**

  
**Input:** s = "3242415"  
**Output:** 5  
**Explanation:** "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.  

**Example 2:**

  
**Input:** s = "12345678"  
**Output:** 1  

**Example 3:**

  
**Input:** s = "213123"  
**Output:** 6  
**Explanation:** "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.  

**Example 4:**

  
**Input:** s = "00"  
**Output:** 2  

**Constraints:**

*   `1 <= s.length <= 10^5`
*   `s` consists only of digits.  



**Solution:**  

```cpp
class Solution {
public:
    int longestAwesome(string s) {
        int counter = 0;
        vector<int> state(1<<10, -1);
        
        state[0] = 0;
        int ans = 0;
        int cur = 0;
        for(int i = 0; i < s.size(); ++i) {
            cur ^= 1 << (s[i] - '0');
            if(state[cur] == -1)
                state[cur] = i + 1;
            ans = max(ans, i - state[cur] + 1);
            for(int j = 0; j <= 9; ++j) {
                int ns = cur ^ (1 << j);
                if(state[ns]>=0)
                    ans = max(ans, i - state[ns] + 1);
            }
        }
        return ans;
        
    }
};
```
      