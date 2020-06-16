[81.search-in-rotated-sorted-array-ii](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)  

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,0,1,2,2,5,6]` might become `[2,5,6,0,0,1,2]`).

You are given a target value to search. If found in the array return `true`, otherwise return `false`.

**Example 1:**

  
**Input:** nums = \[2`,5,6,0,0,1,2]`, target = 0
  
**Output:** true
  

**Example 2:**

  
**Input:** nums = \[2`,5,6,0,0,1,2]`, target = 3
  
**Output:** false

**Follow up:**

*   This is a follow up problem to [Search in Rotated Sorted Array](/problems/search-in-rotated-sorted-array/description/), where `nums` may contain duplicates.
*   Would this affect the run-time complexity? How and why?  



**Solution:**  

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return divide(nums, 0, nums.size()-1, target);
    }
    bool divide(vector<int> &nums, int l , int r, int target){
        while(l <= r){
            int mid = (l+r)/2;
            if( l == r )
                return nums[mid] == target;
            if( nums[l] < nums[r]){
                if( target >= nums[l] && target<= nums[r]){
                    if( nums[mid]> target )
                        r = mid - 1;
                    else if(nums[mid]< target)
                        l = mid + 1;
                    else 
                        return true;
                }else
                    return false;
            }else{
                if( nums[mid] == target)
                    return true;
                bool res = divide(nums, l, mid-1, target);
                bool res1 = divide(nums, mid+1, r, target);
                return res||res1;
            }
        }
        return false;
    }
};
```
      