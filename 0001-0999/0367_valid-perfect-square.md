[367.valid-perfect-square](https://leetcode.com/problems/valid-perfect-square/)  

Given a **positive** integer _num_, write a function which returns True if _num_ is a perfect square else False.

**Follow up:** **Do not** use any built-in library function such as `sqrt`.

**Example 1:**

**Input:** num = 16
**Output:** true

**Example 2:**

**Input:** num = 14
**Output:** false

**Constraints:**

*   `1 <= num <= 2^31 - 1`  



**Solution:**  

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num == 0 ) return true;
        int sq = 1;
        while( sq >= 1 && (sq*sq) < num ){
            sq++;
        }
        return sq*sq == num;
    }
};
```
      