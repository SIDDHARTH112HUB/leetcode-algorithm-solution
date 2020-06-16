[1256.encode-number](https://leetcode.com/problems/encode-number/)  

Given a non-negative integer `num`, Return its _encoding_ string.

The encoding is done by converting the integer to a string using a secret function that you should deduce from the following table:

![](https://assets.leetcode.com/uploads/2019/06/21/encode_number.png)

**Example 1:**

  
**Input:** num = 23
  
**Output:** "1000"
  

**Example 2:**

  
**Input:** num = 107
  
**Output:** "101100"
  

**Constraints:**

*   `0 <= num <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    string encode(int num) {
        num = num + 1;
        string ans;
        while(num > 0) {
            ans +=( (num & 1) + '0');
            num = num >> 1;
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      