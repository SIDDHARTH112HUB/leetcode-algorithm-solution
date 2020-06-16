[1416.restore-the-array](https://leetcode.com/problems/restore-the-array/)  

A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits and all we know is that all integers in the array were in the range `[1, k]` and there are no leading zeros in the array.

Given the string `s` and the integer `k`. There can be multiple ways to restore the array.

Return _the number of possible array_ that can be printed as a string `s` using the mentioned program.

The number of ways could be very large so return it **modulo** `10^9 + 7`

**Example 1:**

  
**Input:** s = "1000", k = 10000
  
**Output:** 1
  
**Explanation:** The only possible array is \[1000\]
  

**Example 2:**

  
**Input:** s = "1000", k = 10
  
**Output:** 0
  
**Explanation:** There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
  

**Example 3:**

  
**Input:** s = "1317", k = 2000
  
**Output:** 8
  
**Explanation:** Possible arrays are \[1317\],\[131,7\],\[13,17\],\[1,317\],\[13,1,7\],\[1,31,7\],\[1,3,17\],\[1,3,1,7\]
  

**Example 4:**

  
**Input:** s = "2020", k = 30
  
**Output:** 1
  
**Explanation:** The only possible array is \[20,20\]. \[2020\] is invalid because 2020 > 30. \[2,020\] is ivalid because 020 contains leading zeros.
  

**Example 5:**

  
**Input:** s = "1234567890", k = 90
  
**Output:** 34
  

**Constraints:**

*   `1 <= s.length <= 10^5`.
*   `s` consists of only digits and doesn't contain leading zeros.
*   `1 <= k <= 10^9`.  



**Solution:**  

```cpp
class Solution {
public:
    long long M = 1e9 + 7;
    unordered_map<long long, long long > m;
    int numberOfArrays(string s, int k) {
        return h(s, 0, s.size()-1, k);
    }
    
    long long h(string &s, int l, int r, int k) {
        if(l > r) return 1;
        if(s[l] == '0') return 0;
        if(l == r) {
            if(s[l] - '0' > k) return 0;
            return 1;
        }
        if(m.count(l)) return m[l];
        long long sum = 0;
        long long res = 0;
        for(int i = l; i <= r; ++i) {
            sum = sum * 10 + (long long)(s[i] - '0');
            if(sum > k)
                break;
            res += 1 * h(s, i + 1, r, k);
        }
        return m[l] = res % M;
    }
};
```
      