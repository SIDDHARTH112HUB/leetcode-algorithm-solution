[440.k-th-smallest-in-lexicographical-order](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/)  

Given integers `n` and `k`, find the lexicographically k-th smallest integer in the range from `1` to `n`.

Note: 1 ≤ k ≤ n ≤ 109.

**Example:**

**Input:**
n: 13   k: 2

**Output:**
10

**Explanation:**
The lexicographical order is \[1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9\], so the second smallest number is 10.  



**Solution:**  

```cpp
class Solution {
public:
    int findKthNumber(int n, int k) {
        long cur = 1;
        --k;
        while(k > 0) {
            long first = cur, last = cur + 1, step = 0;
            while(first <= n) {
                step += min((long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if(step > k) {
                --k;
                cur *= 10;
            }else {
                k -= step;
                ++cur;
            }
        }
        return cur;
    }
};
```
      