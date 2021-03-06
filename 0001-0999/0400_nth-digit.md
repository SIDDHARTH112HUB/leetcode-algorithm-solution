[400.nth-digit](https://leetcode.com/problems/nth-digit/)  

Find the _n_th digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

**Note:**  
_n_ is positive and will fit within the range of a 32-bit signed integer (_n_ < 231).

**Example 1:**

  
**Input:**
  
3
  

  
**Output:**
  
3
  

**Example 2:**

  
**Input:**
  
11
  

  
**Output:**
  
0
  

  
**Explanation:**
  
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.  



**Solution:**  

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        long long cnt = 9, len = 1, start = 1;
        while(cnt * len < n) {
            n -= cnt * len;
            cnt *= 10;
            ++len;
            start *= 10;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n-1)%len] - '0';
    }
};
```
      