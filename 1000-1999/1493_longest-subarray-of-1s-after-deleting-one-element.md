[1493.longest-subarray-of-1s-after-deleting-one-element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)  

Given a binary array `nums`, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.

**Example 1:**

  
**Input:** nums = \[1,1,0,1\]  
**Output:** 3  
**Explanation:** After deleting the number in position 2, \[1,1,1\] contains 3 numbers with value of 1's.

**Example 2:**

  
**Input:** nums = \[0,1,1,1,0,1,1,0,1\]  
**Output:** 5  
**Explanation:** After deleting the number in position 4, \[0,1,1,1,1,1,0,1\] longest subarray with value of 1's is \[1,1,1,1,1\].

**Example 3:**

  
**Input:** nums = \[1,1,1\]  
**Output:** 2  
**Explanation:** You must delete one element.

**Example 4:**

  
**Input:** nums = \[1,1,0,0,1,1,1,0,1\]  
**Output:** 4  

**Example 5:**

  
**Input:** nums = \[0,0,0\]  
**Output:** 0  

**Constraints:**

*   `1 <= nums.length <= 10^5`
*   `nums[i]` is either `0` or `1`.  



**Solution:**  

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> arr;
        int z = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if(n == 0) ++z;
            if(arr.size() == 0) {
                arr.push_back(0);
            }else if(nums[i] != nums[i - 1]) {
                arr.push_back(0);
            }
            if(n == 0) {
                --arr.back();
            }else{
                ++arr.back();
            }
        }
        if(z == 0) return nums.size() - 1;
        int ans = 0;
        for(int i = 0; i < arr.size(); ++i){
            
            int n = arr[i];
            if(n > 0) {
                ans = max(ans, n);
            }else if(n == -1) {
                int sum = 0;
                if(i > 0) {
                    sum += arr[i - 1];
                }
                if(i < arr.size() - 1) {
                    sum += arr[i + 1];
                }
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};
```
      