[441.arranging-coins](https://leetcode.com/problems/arranging-coins/)  

You have a total of _n_ coins that you want to form in a staircase shape, where every _k_\-th row must have exactly _k_ coins.

Given _n_, find the total number of **full** staircase rows that can be formed.

_n_ is a non-negative integer and fits within the range of a 32-bit signed integer.

**Example 1:**

  
n = 5
  

  
The coins can form the following rows:
  
¤
  
¤ ¤
  
¤ ¤
  

  
Because the 3rd row is incomplete, we return 2.
  

**Example 2:**

  
n = 8
  

  
The coins can form the following rows:
  
¤
  
¤ ¤
  
¤ ¤ ¤
  
¤ ¤
  

  
Because the 4th row is incomplete, we return 3.  



**Solution:**  

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        if( n <= 0) return 0;
        int step = 1;
        while( n >= step ){
            n -= step;
            ++step;
        }
        return step-1;
    }
};
```
      