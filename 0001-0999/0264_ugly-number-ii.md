[264.ugly-number-ii](https://leetcode.com/problems/ugly-number-ii/)  

Write a program to find the `n`\-th ugly number.

Ugly numbers are **positive numbers** whose prime factors only include `2, 3, 5`. 

**Example:**

**Input:** n = 10
**Output:** 12
**Explanation:** `1, 2, 3, 4, 5, 6, 8, 9, 10, 12` is the sequence of the first `10` ugly numbers.

**Note:**  

1.  `1` is typically treated as an ugly number.
2.  `n` **does not exceed 1690**.  



**Solution:**  

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        if( n == 0 ) return 0;
        int next2=2, next3=3, next5=5;
        int i2=0, i3=0, i5=0;
        int dp[n] = {0};
        dp[0] = 1;
        for( int i = 1; i<n; i++){
            int next_num = min(next2, min(next3, next5));
            dp[i] = next_num;
            //cout<<next_num<<" ";
            if( next_num == next2 ){
                i2++;
                next2 = dp[i2] * 2;
            }
            if( next_num == next3){
                i3++;
                next3 = dp[i3] * 3;
            }
            if( next_num == next5){
                i5++;
                next5 = dp[i5] * 5;
            }
        }
        return dp[n-1];
    }
};
```
      