[693.binary-number-with-alternating-bits](https://leetcode.com/problems/binary-number-with-alternating-bits/)  

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

**Example 1:**  

  
**Input:** 5
  
**Output:** True
  
**Explanation:**
  
The binary representation of 5 is: 101
  

**Example 2:**  

  
**Input:** 7
  
**Output:** False
  
**Explanation:**
  
The binary representation of 7 is: 111.
  

**Example 3:**  

  
**Input:** 11
  
**Output:** False
  
**Explanation:**
  
The binary representation of 11 is: 1011.
  

**Example 4:**  

  
**Input:** 10
  
**Output:** True
  
**Explanation:**
  
The binary representation of 10 is: 1010.  



**Solution:**  

```cpp
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = n %2;
        int f = flag;
        while(n > 0){
            if( f == n % 2){
                n = n>>1;
                if( f == 0 )
                    f = 1;
                else
                    f = 0;
            }
            else
                return false;
        }
        return true;
    }
};
```
      