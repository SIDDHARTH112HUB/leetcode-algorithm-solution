[397.integer-replacement](https://leetcode.com/problems/integer-replacement/)  

Given a positive integer _n_ and you can do operations as follow:

1.  If _n_ is even, replace _n_ with `_n_/2`.
2.  If _n_ is odd, you can replace _n_ with either `_n_ + 1` or `_n_ - 1`.

What is the minimum number of replacements needed for _n_ to become 1?

**Example 1:**

  
**Input:**
  
8
  

  
**Output:**
  
3
  

  
**Explanation:**
  
8 -> 4 -> 2 -> 1
  

**Example 2:**

  
**Input:**
  
7
  

  
**Output:**
  
4
  

  
**Explanation:**
  
7 -> 8 -> 4 -> 2 -> 1
  
or
  
7 -> 6 -> 3 -> 2 -> 1  



**Solution:**  

```cpp
class Solution {
public:
    int low(int n) { return n & -n; }
    int integerReplacement(long long n) {
        int ans = 0;
        while(n > 1) {
            if(n % 2) {
                long long n1 = (n + 1)>>1;
                long long n2 = (n - 1)>>1;
                ans += 2;
                if(n1 == 1 || n2 == 1)
                    return ans;
                n = low(n1) > low(n2) ? n1 : n2;
            }else{
                n = n >> 1;
                ++ans;
            }
        }
        return ans;
    }
};
```
      