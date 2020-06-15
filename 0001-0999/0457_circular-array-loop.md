[457.circular-array-loop](https://leetcode.com/problems/circular-array-loop/)  

You are given a **circular** array `nums` of positive and negative integers. If a number _k_ at an index is positive, then move forward _k_ steps. Conversely, if it's negative (-_k_), move backward _k_ steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in `nums`. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

**Example 1:**

**Input:** \[2,-1,1,2,2\]
**Output:** true
**Explanation:** There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.

**Example 2:**

**Input:** \[-1,2\]
**Output:** false
**Explanation:** The movement from index 1 -> 1 -> 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.

**Example 3:**

**Input:** \[-2,1,-1,-2,-2\]
**Output:** false
**Explanation:** The movement from index 1 -> 2 -> 1 -> ... is not a cycle, because movement from index 1 -> 2 is a forward movement, but movement from index 2 -> 1 is a backward movement. All movements in a cycle must follow a single direction.

**Note:**

1.  \-1000 ≤ nums\[i\] ≤ 1000
2.  nums\[i\] ≠ 0
3.  1 ≤ nums.length ≤ 5000

**Follow up:**

Could you solve it in **O(n)** time complexity and **O(1)** extra space complexity?  



**Solution:**  

```cpp
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(helper(nums))return true;
        for(int &n : nums)
            n = -n;
        reverse(nums.begin(), nums.end());
        if(helper(nums))return true;
        return false;
    }
    
    bool helper(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if(n < 0) continue;
            int s = 1;
            int prev = i, idx = i;
            while(nums[idx] > 0 && idx >= i) {
                prev = idx;
                (idx += nums[idx]) %= nums.size();
                if(idx == i)break;
                if(prev == idx) break;
                ++s;
                if( s > nums.size()) break;
            }
            if( prev != idx && nums[idx] > 0 && idx >= i) return true;
        }
        return false;
    }
};
```
      