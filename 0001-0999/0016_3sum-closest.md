[16.3sum-closest](https://leetcode.com/problems/3sum-closest/)  

Given an array `nums` of _n_ integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.

**Example 1:**

  
**Input:** nums = \[-1,2,1,-4\], target = 1  
**Output:** 2  
**Explanation:** The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).  

**Constraints:**

*   `3 <= nums.length <= 10^3`
*   `-10^3 <= nums[i] <= 10^3`
*   `-10^4 <= target <= 10^4`  



**Solution:**  

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        for( int i = 0; i<nums.size()-2; i++ ){
            int k = nums.size()-1;
            int j = i+1;
            while(j<k){
                int total = nums[i]+nums[j]+nums[k];
                ans = abs(total-target) < abs( ans - target ) ?total : ans;
                if( total > target ) k--;
                else j++;
            }
        }
        return ans;
    }
};
```
      