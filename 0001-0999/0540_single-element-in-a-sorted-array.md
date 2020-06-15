[540.single-element-in-a-sorted-array](https://leetcode.com/problems/single-element-in-a-sorted-array/)  

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

**Follow up:** Your solution should run in O(log n) time and O(1) space.

**Example 1:**

**Input:** nums = \[1,1,2,3,3,4,4,8,8\]
**Output:** 2

**Example 2:**

**Input:** nums = \[3,3,7,7,10,11,11\]
**Output:** 10

**Constraints:**

*   `1 <= nums.length <= 10^5`
*   `0 <= nums[i] <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int isLeft = 0, isRight = 0;
            if(mid > 0)  isLeft += (nums[mid-1] == nums[mid] ? 1 : 0);
            if(mid < nums.size() - 1) isRight += (nums[mid+1] == nums[mid] ? 1 : 0);
            if(isLeft + isRight == 0) return nums[mid];
            if((mid - l - isLeft) % 2 == 1 && mid - l - isLeft > 0){
                r = mid - 1 - isLeft;
            }else{
                l = mid + 1 + isRight;
            }
        }
        return -1;
    }
};
```
      