[1015.smallest-integer-divisible-by-k](https://leetcode.com/problems/smallest-integer-divisible-by-k/)  

Given a positive integer `K`, you need find the **smallest** positive integer `N` such that `N` is divisible by `K`, and `N` only contains the digit **1**.

Return the length of `N`.  If there is no such `N`, return -1.

**Example 1:**

  
**Input:** 1
  
**Output:** 1
  
**Explanation:** The smallest answer is N = 1, which has length 1.

**Example 2:**

  
**Input:** 2
  
**Output:** -1
  
**Explanation:** There is no such positive integer N divisible by 2.

**Example 3:**

  
**Input:** 3
  
**Output:** 3
  
**Explanation:** The smallest answer is N = 111, which has length 3.

**Note:**

*   `1 <= K <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        long long n = 1;
        int cnt = 1;
        unordered_set<int> m;
        while(true) {
            if(n % K == 0)
                return cnt;
            if(m.count(n))
                return -1;
            m.insert(n);
            n = (n * 10 + 1) % K;
            ++cnt;
        }
        return -1;
    }
};
```
      