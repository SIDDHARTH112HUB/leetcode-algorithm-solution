[1330.reverse-subarray-to-maximize-array-value](https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/)  

You are given an integer array `nums`. The _value_ of this array is defined as the sum of `|nums[i]-nums[i+1]|` for all `0 <= i < nums.length-1`.

You are allowed to select any subarray of the given array and reverse it. You can perform this operation **only once**.

Find maximum possible value of the final array.

**Example 1:**

  
**Input:** nums = \[2,3,1,5,4\]
  
**Output:** 10
  
**Explanation:** By reversing the subarray \[3,1,5\] the array becomes \[2,5,1,3,4\] whose value is 10.
  

**Example 2:**

  
**Input:** nums = \[2,4,9,24,2,1,10\]
  
**Output:** 68
  

**Constraints:**

*   `1 <= nums.length <= 3*10^4`
*   `-10^5 <= nums[i] <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int mx = -111111111, mn = 1111111111, n = nums.size(), res = 0, total = 0;
        for(int i = 1; i < n; ++i) {
            int a = nums[i-1], b = nums[i];
            total += abs(a-b);
            mx = max(mx, min(a, b));
            mn = min(mn, max(a, b));
            res = max(res, abs(nums[0] - b) - abs(a-b));
            res = max(res, abs(nums[n-1] - a) - abs(a-b));
        }
        return total + max(res, (mx-mn) * 2);
    }
};
```
      