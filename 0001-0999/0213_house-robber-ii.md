[213.house-robber-ii](https://leetcode.com/problems/house-robber-ii/)  

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.** That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight **without alerting the police**.

**Example 1:**

**Input:** \[2,3,2\]
**Output:** 3
**Explanation:** You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.

**Example 2:**

**Input:** \[1,2,3,1\]
**Output:** 4
**Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.  



**Solution:**  

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 0 )return 0;
        if( size == 1 ) return nums[0];
        if( size == 2 ) return max(nums[0], nums[1]);
        if( size == 3 ) return max(max(nums[0], nums[1]), nums[2]);
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for( int i = 2; i<size-1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            dp[i-1] = max(dp[i-1], dp[i-2]);
        }
        int ans = dp[size-2];
        dp[0] = 0;
        dp[1] = nums[1];
        for( int i = 2; i<size; i++){
            dp[i] = 0;
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            dp[i-1] = max(dp[i-1], dp[i-2]);
        }
        ans = max(ans, dp[size-1]);
        return ans;
    }
};
```
      