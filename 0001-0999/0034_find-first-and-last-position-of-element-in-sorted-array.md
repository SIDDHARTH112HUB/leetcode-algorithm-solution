[34.find-first-and-last-position-of-element-in-sorted-array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)  

Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

Your algorithm's runtime complexity must be in the order of _O_(log _n_).

If the target is not found in the array, return `[-1, -1]`.

**Example 1:**

  
**Input:** nums = \[`5,7,7,8,8,10]`, target = 8
  
**Output:** \[3,4\]

**Example 2:**

  
**Input:** nums = \[`5,7,7,8,8,10]`, target = 6
  
**Output:** \[-1,-1\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = firstGreaterEqual(nums, target);
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        return {start, firstGreaterEqual(nums, target + 1) - 1};
    }
    int firstGreaterEqual(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
```
      