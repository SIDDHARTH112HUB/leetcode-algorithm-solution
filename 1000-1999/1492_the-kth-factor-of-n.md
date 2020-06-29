[1492.the-kth-factor-of-n](https://leetcode.com/problems/the-kth-factor-of-n/)  

Given two positive integers `n` and `k`.

A factor of an integer `n` is defined as an integer `i` where `n % i == 0`.

Consider a list of all factors of `n` sorted in **ascending order**, return _the_ `kth` _factor_ in this list or return **\-1** if `n` has less than `k` factors.

**Example 1:**

  
**Input:** n = 12, k = 3
  
**Output:** 3
  
**Explanation:** Factors list is \[1, 2, 3, 4, 6, 12\], the 3rd factor is 3.
  

**Example 2:**

  
**Input:** n = 7, k = 2
  
**Output:** 7
  
**Explanation:** Factors list is \[1, 7\], the 2nd factor is 7.
  

**Example 3:**

  
**Input:** n = 4, k = 4
  
**Output:** -1
  
**Explanation:** Factors list is \[1, 2, 4\], there is only 3 factors. We should return -1.
  

**Example 4:**

  
**Input:** n = 1, k = 1
  
**Output:** 1
  
**Explanation:** Factors list is \[1\], the 1st factor is 1.
  

**Example 5:**

  
**Input:** n = 1000, k = 3
  
**Output:** 4
  
**Explanation:** Factors list is \[1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000\].
  

**Constraints:**

*   `1 <= k <= n <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> f;
        for(int i = 1; i <= sqrt(n); ++i) {
            if(n % i == 0) {
                f.push_back(i);
                if(i != n / i) {
                    f.push_back(n/i);
                }
            }
        }
        sort(f.begin(), f.end());
        if(k > f.size()) return -1;
        return f[k - 1];
    }
};
```
      