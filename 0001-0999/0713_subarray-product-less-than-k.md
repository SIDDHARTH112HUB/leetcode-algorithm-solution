[713.subarray-product-less-than-k](https://leetcode.com/problems/subarray-product-less-than-k/)  

Your are given an array of positive integers `nums`.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than `k`.

**Example 1:**  

**Input:** nums = \[10, 5, 2, 6\], k = 100
**Output:** 8
**Explanation:** The 8 subarrays that have product less than 100 are: \[10\], \[5\], \[2\], \[6\], \[10, 5\], \[5, 2\], \[2, 6\], \[5, 2, 6\].
Note that \[10, 5, 2\] is not included as the product of 100 is not strictly less than k.

**Note:**

*   `0 < nums.length <= 50000`.
*   `0 < nums[i] < 1000`.
*   `0 <= k < 10^6`.  



**Solution:**  

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long p = 1;
        int prev = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            p *= nums[i];
            if(p < k) {
                ans += i - prev + 1;
                continue;
            }
            while(prev < i && p >= k) {
                p /= nums[prev++];
            }
            if(nums[i] >= k) continue;
            ans += i - prev + 1;
        }
        return ans;
    }
};
```
      