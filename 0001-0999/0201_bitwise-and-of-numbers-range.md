[201.bitwise-and-of-numbers-range](https://leetcode.com/problems/bitwise-and-of-numbers-range/)  

Given a range \[m, n\] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

**Example 1:**

  
**Input:** \[5,7\]
  
**Output:** 4
  

**Example 2:**

  
**Input:** \[0,1\]
  
**Output:** 0  



**Solution:**  

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = INT_MAX;
        while( ( m &d ) != ( n & d ) ){
            d <<= 1;
        }
        return m & d;
    }
};
```
      