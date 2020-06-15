[560.subarray-sum-equals-k](https://leetcode.com/problems/subarray-sum-equals-k/)  

Given an array of integers and an integer **k**, you need to find the total number of continuous subarrays whose sum equals to **k**.

**Example 1:**

**Input:**nums = \[1,1,1\], k = 2
**Output:** 2

**Constraints:**

*   The length of the array is in range \[1, 20,000\].
*   The range of numbers in the array is \[-1000, 1000\] and the range of the integer **k** is \[-1e7, 1e7\].  



**Solution:**  

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        int sum = 0, ans=0;
        for( int n:nums ){
            sum += n;
            ans += prefix_sum[sum-k];
            prefix_sum[sum] += 1;
        }
        return ans;
    }
};
```
      