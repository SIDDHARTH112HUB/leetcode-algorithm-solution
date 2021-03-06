[581.shortest-unsorted-continuous-subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)  

Given an integer array, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the **shortest** such subarray and output its length.

**Example 1:**  

  
**Input:** \[2, 6, 4, 8, 10, 9, 15\]
  
**Output:** 5
  
**Explanation:** You need to sort \[6, 4, 8, 10, 9\] in ascending order to make the whole array sorted in ascending order.
  

**Note:**  

1.  Then length of the input array is in range \[1, 10,000\].
2.  The input array may contain duplicates, so ascending order here means **<=**.  



**Solution:**  

```cpp
class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -2;
        int n = nums.size();
        int mn = nums[n-1], mx = nums[0];
        for( int i = 1; i < n; i++){
            mx = max(nums[i], mx);
            mn = min(nums[n-1-i], mn);
            if( mx > nums[i]) end = i;
            if( mn < nums[n-1-i]) start = n-1-i;
        }
        return end -start +1;
    }
};
```
      