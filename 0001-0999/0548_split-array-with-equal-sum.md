[548.split-array-with-equal-sum](https://leetcode.com/problems/split-array-with-equal-sum/)  

Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:

1.  0 < i, i + 1 < j, j + 1 < k < n - 1
2.  Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.

where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.

**Example:**  

**Input:** \[1,2,1,2,1,2,1\]
**Output:** True
**Explanation:**
i = 1, j = 3, k = 5. 
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1

**Note:**

1.  1 <= n <= 2000.
2.  Elements in the given array will be in range \[-1,000,000, 1,000,000\].  



**Solution:**  

```cpp
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        int n = nums.size();
        for(int j = 3; j < n -3; ++j) {
            unordered_set<int> s;
            for(int i = 1; i < j - 1; ++i) {
                if(nums[j - 1] - nums[i] == nums[i - 1])
                    s.insert(nums[i-1]);
            }
            for(int k = j + 1; k < n - 1; ++k) {
                if(nums[k-1] - nums[j] == nums.back() - nums[k])
                    if(s.count(nums[k-1] - nums[j]))
                        return true;
            }
        }
        return false;
    }
};
```
      