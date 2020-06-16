[300.longest-increasing-subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)  

Given an unsorted array of integers, find the length of longest increasing subsequence.

**Example:**

  
**Input:** `[10,9,2,5,3,7,101,18]` **Output:** 4 
  
**Explanation:** The longest increasing subsequence is `[2,3,7,101]`, therefore the length is `4`. 

**Note:**

*   There may be more than one LIS combination, it is only necessary for you to return the length.
*   Your algorithm should run in O(_n2_) complexity.

**Follow up:** Could you improve it to O(_n_ log _n_) time complexity?  



**Solution:**  

```cpp
class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; ++j) {
                if( nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size()+1, INT_MAX);
        int size = 1;
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int mid = lower_bound(dp.begin(), dp.begin() + size, nums[i]) - dp.begin();
            if(mid > 0)
                size = max(mid + 1, size);
            dp[mid] = min(dp[mid], nums[i]);
        }
        
        return size;
    }
};
```
      