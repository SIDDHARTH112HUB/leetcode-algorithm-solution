[357.count-numbers-with-unique-digits](https://leetcode.com/problems/count-numbers-with-unique-digits/)  

Given a **non-negative** integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

**Example:**

**Input:** 2
**Output:** 91 
**Explanation:** The answer should be the total numbers in the range of 0 ≤ x < 100, 
             excluding `11,22,33,44,55,66,77,88,99`  



**Solution:**  

```cpp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if( n<=0) return 1;
        if(n > 10 ) n =10;
        int dp[11] = {0};
        dp[1] = 10;
        //cout<<"begin "<<endl;
        for( int i = 2; i<=n; i++ ){
            int p = 9;
            for(int j = 0; j<i-1; j++){
                p *= (9-j);
            }
            //cout<<p<<endl;
            dp[i] = dp[i-1] + p;
        }
        return dp[n];
    }
};
```
      