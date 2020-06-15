[33.search-in-rotated-sorted-array](https://leetcode.com/problems/search-in-rotated-sorted-array/)  

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

You are given a target value to search. If found in the array return its index, otherwise return `-1`.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of _O_(log _n_).

**Example 1:**

**Input:** nums = \[`4,5,6,7,0,1,2]`, target = 0
**Output:** 4

**Example 2:**

**Input:** nums = \[`4,5,6,7,0,1,2]`, target = 3
**Output:** -1  



**Solution:**  

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right= nums.size();
        if( right == 0 ) return -1;
        if( right == 1) return nums[0] == target? 0:-1;
        int mid = (left+ right)/2;
        if(nums[right-1] < nums[0]){
            while( nums[mid] > nums[mid-1] ){
                if( nums[mid] > nums[0] ){
                    left = mid;
                }else{
                    right = mid;
                }
                mid = (left+right)/2;
            }
            //cout<<mid<<endl;
        }
        int pivot = mid;
        left = 0;
        right=mid;
        while(left<=right){
            int part_mid = (left+right)/2;
            if( nums[part_mid] < target){
                left = part_mid+1;
            }else if( nums[part_mid]> target){
                right = part_mid-1;
            }else{
                return part_mid;
            }
        }
        left = mid, right=nums.size();
        while(left<=right){
            int part_mid = (left+right)/2;
            if( nums[part_mid] < target){
                left = part_mid+1;
            }else if( nums[part_mid]> target){
                right = part_mid-1;
            }else{
                return part_mid;
            }
        }
        return -1;
    }
};
```
      