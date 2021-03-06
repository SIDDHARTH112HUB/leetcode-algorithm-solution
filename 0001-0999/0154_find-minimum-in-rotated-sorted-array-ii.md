[154.find-minimum-in-rotated-sorted-array-ii](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)  

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  `[0,1,2,4,5,6,7]` might become  `[4,5,6,7,0,1,2]`).

Find the minimum element.

The array may contain duplicates.

**Example 1:**

  
**Input:** \[1,3,5\]
  
**Output:** 1

**Example 2:**

  
**Input:** \[2,2,2,0,1\]
  
**Output:** 0

**Note:**

*   This is a follow up problem to [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/).
*   Would allow duplicates affect the run-time complexity? How and why?  



**Solution:**  

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        
        int prev = nums[0];
        if( nums.size() == 1 ) return prev;
        for( int i = 1; i<nums.size(); i++ ){
            if( nums[i-1]>nums[i] )
                return nums[i];
        }
        return prev;
    }
};
```
      