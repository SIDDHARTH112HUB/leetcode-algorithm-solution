[259.3sum-smaller](https://leetcode.com/problems/3sum-smaller/)  

Given an array of _n_ integers _nums_ and a _target_, find the number of index triplets `i, j, k` with `0 <= i < j < k < n` that satisfy the condition `nums[i] + nums[j] + nums[k] < target`.

**Example:**

  
**Input:** _nums_ = `[-2,0,1,3]`, and _target_ = 2
  
**Output:** 2 
  
**Explanation:** Because there are two triplets which sums are less than 2:
  
             \[-2,0,1\]
  
             \[-2,0,3\]
  

**Follow up:** Could you solve it in _O_(_n_2) runtime?  



**Solution:**  

```cpp
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            for(int j = i + 1; j < nums.size(); ++j) {
                int b = nums[j];
                int c = target - a - b;
                ans += lower_bound(nums.begin() + j + 1, nums.end(), c) - nums.begin() - j - 1;
            }
        }
        return ans;
    }
};
```
      