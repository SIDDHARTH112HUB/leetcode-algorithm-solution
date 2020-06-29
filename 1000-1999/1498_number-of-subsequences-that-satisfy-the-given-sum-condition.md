[1498.number-of-subsequences-that-satisfy-the-given-sum-condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)  

Given an array of integers `nums` and an integer `target`.

Return the number of **non-empty** subsequences of `nums` such that the sum of the minimum and maximum element on it is less or equal than `target`.

Since the answer may be too large, return it modulo 10^9 + 7.

**Example 1:**

  
**Input:** nums = \[3,5,6,7\], target = 9  
**Output:** 4  
**Explanation:** There are 4 subsequences that satisfy the condition.  
\[3\] -> Min value + max value <= target (3 + 3 <= 9)  
\[3,5\] -> (3 + 5 <= 9)  
\[3,5,6\] -> (3 + 6 <= 9)  
\[3,6\] -> (3 + 6 <= 9)  

**Example 2:**

  
**Input:** nums = \[3,3,6,8\], target = 10  
**Output:** 6  
**Explanation:** There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).  
\[3\] , \[3\] , \[3,3\], \[3,6\] , \[3,6\] , \[3,3,6\]

**Example 3:**

  
**Input:** nums = \[2,3,3,4,6,7\], target = 12  
**Output:** 61  
**Explanation:** There are 63 non-empty subsequences, two of them don't satisfy the condition (\[6,7\], \[7\]).  
Number of valid subsequences (63 - 2 = 61).  

**Example 4:**

  
**Input:** nums = \[5,2,4,1,7,6,8\], target = 16  
**Output:** 127  
**Explanation:** All non-empty subset satisfy the condition (2^7 - 1) = 127

**Constraints:**

*   `1 <= nums.length <= 10^5`
*   `1 <= nums[i] <= 10^6`
*   `1 <= target <= 10^6`  



**Solution:**  

```cpp
class Solution {
public:
    map<long long, long long> dp;
    long long fastP(int n) {
        if(n == 0) return 1;
        if(n == 1) return 2;
        if(dp.count(n)) return dp[n];
        long long a = fastP(n / 2);
        
        return dp[n] = (a * a * (n % 2? 2 : 1)) % 1000000007 ;
        
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            int sub = target - n;
            auto idx = upper_bound(nums.begin(), nums.end(), sub) - nums.begin();
            if(idx <= i) continue;
            
            ans += 1 + fastP(idx - i - 1) - 1;
            ans %= 1000000007;
        }
        return ans;
    }
};
```
      