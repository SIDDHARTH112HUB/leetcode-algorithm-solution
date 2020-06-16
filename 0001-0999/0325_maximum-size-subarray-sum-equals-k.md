[325.maximum-size-subarray-sum-equals-k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)  

Given an array _nums_ and a target value _k_, find the maximum length of a subarray that sums to _k_. If there isn't one, return 0 instead.

**Note:**  
The sum of the entire _nums_ array is guaranteed to fit within the 32-bit signed integer range.

**Example 1:**

  
**Input:** _nums_ = `[1, -1, 5, -2, 3]`, _k_ = `3`
  
**Output:** 4 
  
**Explanation:** The subarray `[1, -1, 5, -2]` sums to 3 and is the longest.
  

**Example 2:**

  
**Input:** _nums_ = `[-2, -1, 2, 1]`, _k_ = `1`
  
**Output:** 2 **Explanation:** The subarray `[-1, 2]` sums to 1 and is the longest.

**Follow Up:**  
Can you do it in O(_n_) time?  



**Solution:**  

```cpp
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            int n = nums[i];
            sum += n;
            if(m.count(sum - k))
                ans = max(ans, i - m[sum - k]);
            if(m.count(sum) == 0)
                m[sum] = i;
        }
        return ans;
    }
};
```
      