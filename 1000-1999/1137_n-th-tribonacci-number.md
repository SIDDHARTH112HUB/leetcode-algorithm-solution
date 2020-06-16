[1137.n-th-tribonacci-number](https://leetcode.com/problems/n-th-tribonacci-number/)  

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given `n`, return the value of Tn.

**Example 1:**

  
**Input:** n = 4
  
**Output:** 4
  
**Explanation:**
  
T\_3 = 0 + 1 + 1 = 2
  
T\_4 = 1 + 1 + 2 = 4
  

**Example 2:**

  
**Input:** n = 25
  
**Output:** 1389537
  

**Constraints:**

*   `0 <= n <= 37`
*   The answer is guaranteed to fit within a 32-bit integer, ie. `answer <= 2^31 - 1`.  



**Solution:**  

```cpp
class Solution {
public:
    int tribonacci(int n) {
        vector<long long> a(100);
        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        for(int i = 3; i < n+3; ++i){
            a[i] = a[i-2] + a[i-1] + a[i-3];
        }
        return a[n];
    }
};
```
      