[136.single-number](https://leetcode.com/problems/single-number/)  

Given a **non-empty** array of integers, every element appears _twice_ except for one. Find that single one.

**Note:**

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**Example 1:**

  
**Input:** \[2,2,1\]
  
**Output:** 1
  

**Example 2:**

  
**Input:** \[4,1,2,1,2\]
  
**Output:** 4  



**Solution:**  

```cpp
class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for(int i = 0; i< n; i++)
        {
            result ^= A[i];
        }
        return result;
    }
};
```
      