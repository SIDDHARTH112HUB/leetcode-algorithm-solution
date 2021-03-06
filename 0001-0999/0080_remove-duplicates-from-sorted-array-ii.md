[80.remove-duplicates-from-sorted-array-ii](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)  

Given a sorted array _nums_, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that duplicates appeared at most _twice_ and return the new length.

Do not allocate extra space for another array, you must do this by **modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** with O(1) extra memory.

**Example 1:**

  
Given _nums_ = **\[1,1,1,2,2,3\]**,
  

  
Your function should return length = **`5`**, with the first five elements of _`nums`_ being **`1, 1, 2, 2`** and **3** respectively.
  

  
It doesn't matter what you leave beyond the returned length.

**Example 2:**

  
Given _nums_ = **\[0,0,1,1,1,1,2,3,3\]**,
  

  
Your function should return length = **`7`**, with the first seven elements of _`nums`_ being modified to **`0`**, **0**, **1**, **1**, **2**, **3** and **3** respectively.
  

  
It doesn't matter what values are set beyond the returned length.
  

**Clarification:**

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by **reference**, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

  
// **nums** is passed in by reference. (i.e., without making a copy)
  
int len = removeDuplicates(nums);
  

  
// any modification to **nums** in your function would be known by the caller.
  
// using the length returned by your function, it prints the first **len** elements.
  
for (int i = 0; i < len; i++) {
  
    print(nums\[i\]);
  
}  



**Solution:**  

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for(int n:nums)
            if( cnt<2 || n>nums[cnt-2])
                nums[cnt++] = n;
        return cnt;
        /*
        int count = 0;
        for( int i = 2; i<nums.size(); i++){
            if( nums[i] == nums[i-2-count]) count++;
            else nums[i-count] = nums[i];
        }
        return nums.size()-count;
        */
    }
};
```
      