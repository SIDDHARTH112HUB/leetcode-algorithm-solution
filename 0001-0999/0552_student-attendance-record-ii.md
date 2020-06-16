[552.student-attendance-record-ii](https://leetcode.com/problems/student-attendance-record-ii/)  

Given a positive integer **n**, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

1.  **'A'** : Absent.
2.  **'L'** : Late.
3.  **'P'** : Present.

A record is regarded as rewardable if it doesn't contain **more than one 'A' (absent)** or **more than two continuous 'L' (late)**.

**Example 1:**  

  
**Input:** n = 2
  
**Output:** 8 
  
**Explanation:**
  
There are 8 records with length 2 will be regarded as rewardable:
  
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
  
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
  

**Note:** The value of **n** won't exceed 100,000.  



**Solution:**  

```cpp
class Solution {
public:
    int checkRecord(int n) {
        long long dp[n+5] = {0};
        long long M = 1000000007;
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        dp[3] = 7;
        for(int i = 4; i <= n; ++i) {
            dp[i] += dp[i-1] % M;
            dp[i] += (dp[i-1] + (M- dp[i-4]) % M) %M;
        }
        for(int i = 0; i < n ;++i) {
            dp[n] += (dp[i] * dp[n-i-1]) %M;
        }
        return dp[n] % M;
    }
};
```
      