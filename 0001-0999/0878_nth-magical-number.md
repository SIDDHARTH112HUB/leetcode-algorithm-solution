[878.nth-magical-number](https://leetcode.com/problems/nth-magical-number/)  

A positive integer is _magical_ if it is divisible by either A or B.

Return the N\-th magical number.  Since the answer may be very large, **return it modulo** `10^9 + 7`.

**Example 1:**

**Input:** N = 1, A = 2, B = 3
**Output:** 2

**Example 2:**

**Input:** N = 4, A = 2, B = 3
**Output:** 6

**Example 3:**

**Input:** N = 5, A = 2, B = 4
**Output:** 10

**Example 4:**

**Input:** N = 3, A = 6, B = 4
**Output:** 8

**Note:**

1.  `1 <= N <= 10^9`
2.  `2 <= A <= 40000`
3.  `2 <= B <= 40000`  



**Solution:**  

```cpp
class Solution {
public:
    int gcd(int a, int b){
        return a%b==0? b:gcd(b, a % b);
    }
    int nthMagicalNumber(int N, int A, int B) {
        long long l = 2, r = 1e15, a = gcd(A, B),mod = 1e9 + 7;
        //cout<<a<<endl;
        while(l < r ){
            long long m = (l + r )/2;
            if( m / A + m / B - m* a/A/B < N)
                l = m + 1;
            else
                r = m;
        }
        return l%mod;
    }
};
```
      