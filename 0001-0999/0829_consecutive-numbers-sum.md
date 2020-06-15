[829.consecutive-numbers-sum](https://leetcode.com/problems/consecutive-numbers-sum/)  

Given a positive integer `N`, how many ways can we write it as a sum of consecutive positive integers?

**Example 1:**

**Input:** 5
**Output:** 2
**Explanation:** 5 = 5 = 2 + 3

**Example 2:**

**Input:** 9
**Output:** 3
**Explanation:** 9 = 9 = 4 + 5 = 2 + 3 + 4

**Example 3:**

**Input:** 15
**Output:** 4
**Explanation:** 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5

**Note:** `1 <= N <= 10 ^ 9`.  



**Solution:**  

```cpp
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            int n = N - i * (i + 1 ) /2;
            if(n < 0) break;
            if(n % i == 0)
                ++ans;
        }
        return ans;
    }
};
```
      