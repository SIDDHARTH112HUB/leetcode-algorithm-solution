[209.minimum-size-subarray-sum](https://leetcode.com/problems/minimum-size-subarray-sum/)  

Given an array of **n** positive integers and a positive integer **s**, find the minimal length of a **contiguous** subarray of which the sum ≥ **s**. If there isn't one, return 0 instead.

**Example:** 

**Input:** `s = 7, nums = [2,3,1,2,4,3]`
**Output:** 2
**Explanation:** the subarray `[4,3]` has the minimal length under the problem constraint.

**Follow up:**

If you have figured out the _O_(_n_) solution, try coding another solution of which the time complexity is _O_(_n_ log _n_).  



**Solution:**  

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end=0, ans = INT_MAX, sum = 0;
        for( start = 0; start < nums.size(); start++){
            while( end < nums.size() && sum < s){
                sum += nums[end++];
            }
            if( sum >= s ){
                ans = min(ans, end-start);
                sum -= nums[start];
            }
        }
        return ans == INT_MAX ? 0: ans;
    }
};
```
      