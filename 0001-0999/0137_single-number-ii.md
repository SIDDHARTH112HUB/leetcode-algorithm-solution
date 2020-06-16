[137.single-number-ii](https://leetcode.com/problems/single-number-ii/)  

Given a **non-empty** array of integers, every element appears _three_ times except for one, which appears exactly once. Find that single one.

**Note:**

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**Example 1:**

  
**Input:** \[2,2,3,2\]
  
**Output:** 3
  

**Example 2:**

  
**Input:** \[0,1,0,1,0,1,99\]
  
**Output:** 99  



**Solution:**  

```cpp
class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitnum[32];
        int res=0;
        memset(bitnum, 0, sizeof(bitnum));
        for(int j = 0; j<32; j++)
        {
            for(int i = 0; i < n ; i++)
            {
                bitnum[j] += ((A[i]>>j) & 0x01);
            }
            res |= (bitnum[j]%3)<<j;
        }
        return res;
    }
};
```
      