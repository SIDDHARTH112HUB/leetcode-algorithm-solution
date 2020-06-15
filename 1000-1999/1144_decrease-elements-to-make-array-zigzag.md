[1144.decrease-elements-to-make-array-zigzag](https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/)  

Given an array `nums` of integers, a _move_ consists of choosing any element and **decreasing it by 1**.

An array `A` is a _zigzag array_ if either:

*   Every even-indexed element is greater than adjacent elements, ie. `A[0] > A[1] < A[2] > A[3] < A[4] > ...`
*   OR, every odd-indexed element is greater than adjacent elements, ie. `A[0] < A[1] > A[2] < A[3] > A[4] < ...`

Return the minimum number of moves to transform the given array `nums` into a zigzag array.

**Example 1:**

**Input:** nums = \[1,2,3\]
**Output:** 2
**Explanation:** We can decrease 2 to 0 or 3 to 1.

**Example 2:**

**Input:** nums = \[9,6,1,6,2\]
**Output:** 4

**Constraints:**

*   `1 <= nums.length <= 1000`
*   `1 <= nums[i] <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    int helper(vector<int> &nums, int idx) {
        int ans = 0;
        for(int i = idx; i < nums.size(); i+=2) {
            int l = i == 0 ? 10001: nums[i-1];
            int r = i == nums.size()-1 ? 10001: nums[i+1];
            if(min(r, l) <= nums[i])
                ans += nums[i] - min(r, l) + 1;
        }
        return ans;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(helper(nums, 0), helper(nums, 1));
    }
};
```
      