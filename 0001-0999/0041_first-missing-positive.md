[41.first-missing-positive](https://leetcode.com/problems/first-missing-positive/)  

Given an unsorted integer array, find the smallest missing positive integer.

**Example 1:**

  
Input: \[1,2,0\]
  
Output: 3
  

**Example 2:**

  
Input: \[3,4,-1,1\]
  
Output: 2
  

**Example 3:**

  
Input: \[7,8,9,11,12\]
  
Output: 1
  

**Note:**

Your algorithm should run in _O_(_n_) time and uses constant extra space.  



**Solution:**  

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
```
      