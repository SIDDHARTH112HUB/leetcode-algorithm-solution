[487.max-consecutive-ones-ii](https://leetcode.com/problems/max-consecutive-ones-ii/)  

Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

**Example 1:**  

  
**Input:** \[1,0,1,1,0\]
  
**Output:** 4
  
**Explanation:** Flip the first zero will get the the maximum number of consecutive 1s.
  
    After flipping, the maximum number of consecutive 1s is 4.
  

**Note:**

*   The input array will only contain `0` and `1`.
*   The length of input array is a positive integer and will not exceed 10,000

**Follow up:**  
What if the input numbers come in one by one as an **infinite stream**? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?  



**Solution:**  

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> arr(2);
        bool flip = false;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                ++arr[flip];
                flip = !flip;
                arr[flip] = 0;
            }
            else ++arr[flip];
            ans = max(ans, arr[0] + arr[1]);
        }
        return ans;
    }
};
```
      