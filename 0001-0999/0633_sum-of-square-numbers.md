[633.sum-of-square-numbers](https://leetcode.com/problems/sum-of-square-numbers/)  

Given a non-negative integer `c`, your task is to decide whether there're two integers `a` and `b` such that a2 + b2 = c.

**Example 1:**

**Input:** 5
**Output:** True
**Explanation:** 1 \* 1 + 2 \* 2 = 5

**Example 2:**

**Input:** 3
**Output:** False  



**Solution:**  

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        int sqc = sqrt(c);
        for(int i = 1; i <= sqc; ++i) {
            int b = c - i * i;
            int sb = sqrt(b);
            if(sb * sb + i * i == c)
                return true;
        }
        return false;
    }
};
```
      