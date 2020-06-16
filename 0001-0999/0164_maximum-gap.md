[164.maximum-gap](https://leetcode.com/problems/maximum-gap/)  

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

**Example 1:**

  
**Input:** \[3,6,9,1\]
  
**Output:** 3
  
**Explanation:** The sorted form of the array is \[1,3,6,9\], either
  
             (3,6) or (6,9) has the maximum difference 3.

**Example 2:**

  
**Input:** \[10\]
  
**Output:** 0
  
**Explanation:** The array contains less than 2 elements, therefore return 0.

**Note:**

*   You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*   Try to solve it in linear time/space.  



**Solution:**  

```cpp
class Solution {
public:
    int maximumGap1(vector<int>& nums) {
        if( nums.size() <= 1) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for( int i = 0; i<nums.size()-1; i++){
            int gap = abs(nums[i+1] - nums[i]);
            if( gap > ans)
                ans = gap;
        }
        return ans;
    }
    
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        const auto mm = minmax_element(nums.begin(), nums.end());
        const int range = *mm.second - *mm.first;
        const int bin_size = range / n + 1;
        vector<int> min_vals(n, INT_MAX);
        vector<int> max_vals(n, INT_MIN);
        for (const int num : nums) {
            const int index = (num - *mm.first) / bin_size;
            min_vals[index] = min(min_vals[index], num);
            max_vals[index] = max(max_vals[index], num);
        }
        
        int max_gap = 0;
        int prev_max = max_vals[0];
        for (int i = 1; i < n; ++i) {
            if (min_vals[i] != INT_MAX) {
                max_gap = max(max_gap, min_vals[i] - prev_max);
                prev_max = max_vals[i];
            }
        }
        return max_gap;
    }
};
```
      