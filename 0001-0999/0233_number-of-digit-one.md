[233.number-of-digit-one](https://leetcode.com/problems/number-of-digit-one/)  

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

**Example:**

**Input:** 13
**Output:** 6 
**Explanation:** Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.  



**Solution:**  

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;
        for(long long m = 1; m <=n; m*=10) {
            int a = n / m, b = n % m;
            ans += (a + 8) / 10 * m + ( a % 10 == 1 ? b + 1 : 0);
        }
        return ans;
    }
};
```
      