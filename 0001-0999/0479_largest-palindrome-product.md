[479.largest-palindrome-product](https://leetcode.com/problems/largest-palindrome-product/)  

Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

**Example:**

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

**Note:**

The range of n is \[1,8\].  



**Solution:**  

```cpp
class Solution {
public:
    int largestPalindrome(int n) {
        long l = pow(10, n - 1), r = pow(10, n) - 1;
        for(long num = r; num >=l; --num) {
            string str = to_string(num);
            long p = stol(str + string(str.rbegin(), str.rend()));
            for(long j = r; j * j >= p; --j) {
                if( p% j == 0) return p%1337;
            }
        }
        return 9;
    }
};
```
      