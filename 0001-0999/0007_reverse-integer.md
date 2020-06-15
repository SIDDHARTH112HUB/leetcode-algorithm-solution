[7.reverse-integer](https://leetcode.com/problems/reverse-integer/)  

Given a 32-bit signed integer, reverse digits of an integer.

**Example 1:**

**Input:** 123
**Output:** 321

**Example 2:**

**Input:** -123
**Output:** -321

**Example 3:**

**Input:** 120
**Output:** 21

**Note:**  
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: \[−231,  231 − 1\]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.  



**Solution:**  

```cpp
class Solution {
public:
    int reverse(int x) {
        if( abs(x)<10 ) return x;
        long long i=0;
        bool positive = (x < 0);
        x = abs(x);
        while( x%10 == 0)
        {
            x /= 10;
        }
        while( x > 0)
        {
            i = i*10 + x%10;
            x = x/10;
        }
        i = i * (positive==true?-1:1);
        if( i < -2147483648)
            return 0;
        if( i > 2147483647 )
            return 0;
        return i;
    }
};
```
      