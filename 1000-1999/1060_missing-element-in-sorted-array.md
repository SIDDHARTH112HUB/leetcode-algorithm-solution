[1060.missing-element-in-sorted-array](https://leetcode.com/problems/missing-element-in-sorted-array/)  

Given a sorted array `A` of **unique** numbers, find the `_K_-th` missing number starting from the leftmost number of the array.

**Example 1:**

**Input:** A = \[4,7,9,10\], K = 1
**Output:** 5
**Explanation:** 
The first missing number is 5.

**Example 2:**

**Input:** A = \[4,7,9,10\], K = 3
**Output:** 8
**Explanation:** 
The missing numbers are \[5,6,8,...\], hence the third missing number is 8.

**Example 3:**

**Input:** A = \[1,2,4\], K = 3
**Output:** 6
**Explanation:** 
The missing numbers are \[3,5,6,7,...\], hence the third missing number is 6.

**Note:**

1.  `1 <= A.length <= 50000`
2.  `1 <= A[i] <= 1e7`
3.  `1 <= K <= 1e8`  



**Solution:**  

```cpp
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0, h = nums.size();
        while(l < h) {
            int m = l + (h - l) / 2;
            nums[m] - m - k >= nums[0] ? h = m : l = m + 1;
        }
        return nums[0] + l + k - 1;
    }
};
```
      