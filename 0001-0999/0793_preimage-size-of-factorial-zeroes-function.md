[793.preimage-size-of-factorial-zeroes-function](https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/)  

Let `f(x)` be the number of zeroes at the end of `x!`. (Recall that `x! = 1 * 2 * 3 * ... * x`, and by convention, `0! = 1`.)

For example, `f(3) = 0` because 3! = 6 has no zeroes at the end, while `f(11) = 2` because 11! = 39916800 has 2 zeroes at the end. Given `K`, find how many non-negative integers `x` have the property that `f(x) = K`.

  
**Example 1:**
  
**Input:** K = 0
  
**Output:** 5
  
**Explanation:** 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.
  

  
**Example 2:**
  
**Input:** K = 5
  
**Output:** 0
  
**Explanation:** There is no x such that x! ends in K = 5 zeroes.
  

**Note:**

*   `K` will be an integer in the range `[0, 10^9]`.  



**Solution:**  

```cpp
class Solution {
public:
    int preimageSizeFZF(int K) {
        long long l = 0, r = INT_MAX;
        r *= 10;
        while(l < r) {
            long long mid = l + (r - l) / 2;
            long long n = zeros(mid);
            if(n == K)
                return 5;
            else if(n > K)
                r = mid;
            else
                l = mid + 1;
        }
        return 0;
    }
    
    long long zeros(long long n) {
        return n == 0 ? 0 : n / 5 + zeros(n / 5);
    }
};
```
      