[50.powx-n](https://leetcode.com/problems/powx-n/)  

Implement [pow(_x_, _n_)](http://www.cplusplus.com/reference/valarray/pow/), which calculates _x_ raised to the power _n_ (xn).

**Example 1:**

  
**Input:** 2.00000, 10
  
**Output:** 1024.00000
  

**Example 2:**

  
**Input:** 2.10000, 3
  
**Output:** 9.26100
  

**Example 3:**

  
**Input:** 2.00000, -2
  
**Output:** 0.25000
  
**Explanation:** 2\-2 = 1/22 = 1/4 = 0.25
  

**Note:**

*   \-100.0 < _x_ < 100.0
*   _n_ is a 32-bit signed integer, within the range \[−231, 231 − 1\]  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<long long, double> memo;
    double myPow(double x, long long n) {
        bool revert = false;
        if( n < 0 ) {
            n = -n;
            revert = true;
        }
        double p = 1;
        while( n>0){
            if( n&1 )
                p*=x;
            
            x*=x;
            n = n>>1;
        }
        if( revert)
            p = 1/p;
        return p;
    }
};
```
      