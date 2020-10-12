[1567.maximum-length-of-subarray-with-positive-product](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/)  

Given an array of integers `nums`, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return _the maximum length of a subarray with positive product_.

**Example 1:**

  
**Input:** nums = \[1,-2,-3,4\]  
**Output:** 4  
**Explanation:** The array nums already has a positive product of 24.  

**Example 2:**

  
**Input:** nums = \[0,1,-2,-3,-4\]  
**Output:** 3  
**Explanation:** The longest subarray with positive product is \[1,-2,-3\] which has a product of 6.  
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.

**Example 3:**

  
**Input:** nums = \[-1,-2,-3,0,1\]  
**Output:** 2  
**Explanation:** The longest subarray with positive product is \[-1,-2\] or \[-2,-3\].  

**Example 4:**

  
**Input:** nums = \[-1,2\]  
**Output:** 1  

**Example 5:**

  
**Input:** nums = \[1,2,3,5,-6,4,0,10\]  
**Output:** 4  

**Constraints:**

*   `1 <= nums.length <= 10^5`
*   `-10^9 <= nums[i] <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int prev = -1;
        int sign = 1;
        int neg = 0, pos = 0;
        int lastneg = -1;
        int start = -1;
        int ans = 0;
        map<int, int> m;
        m[1] = -1;
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if(n > 0) ++pos;
            else if(n < 0) {
                ++neg;
                if(lastneg == -1)
                    lastneg = i;
            }else if(n == 0) {
                neg = 0, pos = 0;
                lastneg = -1;
                start = i;
            }
            if(neg % 2 == 0) {
                ans = max(ans, i - start);
            }else {
                if(lastneg != -1)
                    ans = max(ans, i - lastneg);
                else
                    ans = max(ans, i - start);
            }
        }
        return ans;
    }
};
```
      