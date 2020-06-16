[390.elimination-game](https://leetcode.com/problems/elimination-game/)  

There is a list of sorted integers from 1 to _n_. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length _n_.

**Example:**

  
Input:
  
n = 9,
  
1 2 3 4 5 6 7 8 9
  
2 4 6 8
  
2 6
  
6
  

  
Output:
  
6  



**Solution:**  

```cpp
class Solution {
public:
    int lastRemaining(int n) {
        int res = 1, step = 1;
        while(step * 2 <=n ) {
            res += step;
            step *= 2;
            if(step * 2 > n) break;
            if( (n/step) % 2 ) res += step;
            step *= 2;
        }
        return res;
    }
};
```
      