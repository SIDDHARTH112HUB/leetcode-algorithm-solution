[153.find-minimum-in-rotated-sorted-array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)  

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  `[0,1,2,4,5,6,7]` might become  `[4,5,6,7,0,1,2]`).

Find the minimum element.

You may assume no duplicate exists in the array.

**Example 1:**

  
**Input:** \[3,4,5,1,2\] 
  
**Output:** 1
  

**Example 2:**

  
**Input:** \[4,5,6,7,0,1,2\]
  
**Output:** 0  



**Solution:**  

```python
class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        left = 0
        l = len(num)
        if l == 1: return num[0]
        if l== 2: return num[0]>num[1] and num[1] or num[0]
        right = l-1
        while left!=right:
            mid = (left+right)/2
            if num[mid]<num[mid+1] and num[mid]<num[mid-1]:
                return num[mid]
            if num[mid]>num[right]:
                left = mid+1
            else:
                right = mid-1
        return num[left]
```
      