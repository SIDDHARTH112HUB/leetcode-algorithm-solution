[1201.ugly-number-iii](https://leetcode.com/problems/ugly-number-iii/)  

Write a program to find the `n`\-th ugly number.

Ugly numbers are **positive integers** which are divisible by `a` **or** `b` **or** `c`.

**Example 1:**

**Input:** n = 3, a = 2, b = 3, c = 5
**Output:** 4
**Explanation:** The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

**Example 2:**

**Input:** n = 4, a = 2, b = 3, c = 4
**Output:** 6
**Explanation:** The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.

**Example 3:**

**Input:** n = 5, a = 2, b = 11, c = 13
**Output:** 10
**Explanation:** The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.

**Example 4:**

**Input:** n = 1000000000, a = 2, b = 217983653, c = 336916467
**Output:** 1999999984

**Constraints:**

*   `1 <= n, a, b, c <= 10^9`
*   `1 <= a * b * c <= 10^18`
*   It's guaranteed that the result will be in range `[1, 2 * 10^9]`  



**Solution:**  

```cpp
long long gcd(long long a, long long b) {
    if( a < b) return gcd(b, a);
    if( b == 0) return a;
    if( a % b == 0) return b;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}
class Solution {
public:
    int nthUglyNumber(long long n, long long a, long long b, long long c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(c, ab);
        long long l = a, r = INT_MAX;
        while(l < r) {
            long long mid = (l + r) / 2;
            long long num = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid /abc;
            if(num < n) {
                l = mid + 1;
            }else if( num >= n)
                r = mid;
        }
        return r;
    }
};
```
      