[172.factorial-trailing-zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/)  

Given an integer _n_, return the number of trailing zeroes in _n_!.

**Example 1:**

  
**Input:** 3
  
**Output:** 0
  
**Explanation:** 3! = 6, no trailing zero.

**Example 2:**

  
**Input:** 5
  
**Output:** 1
  
**Explanation:** 5! = 120, one trailing zero.

**Note:** Your solution should be in logarithmic time complexity.  



**Solution:**  

```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};
```
      