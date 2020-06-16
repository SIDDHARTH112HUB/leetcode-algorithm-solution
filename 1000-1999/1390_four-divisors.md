[1390.four-divisors](https://leetcode.com/problems/four-divisors/)  

Given an integer array `nums`, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return `0`.

**Example 1:**

  
**Input:** nums = \[21,4,7\]  
**Output:** 32  
**Explanation:**  
21 has 4 divisors: 1, 3, 7, 21  
4 has 3 divisors: 1, 2, 4  
7 has 2 divisors: 1, 7  
The answer is the sum of divisors of 21 only.  

**Constraints:**

*   `1 <= nums.length <= 10^4`
*   `1 <= nums[i] <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int n : nums) {
            int sq = sqrt(n);
            int sum = 0;
            int cnt = 0;
            for(int i = 1; i <= sq; ++i) {
                if(n % i == 0) {
                    sum = sum + i;
                    ++cnt;
                    if(n /i != i){
                        sum += n / i;
                        ++cnt;
                    }
                }
            }
            if(cnt == 4)
                ans += sum;
        }
        return ans;
    }
};
```
      