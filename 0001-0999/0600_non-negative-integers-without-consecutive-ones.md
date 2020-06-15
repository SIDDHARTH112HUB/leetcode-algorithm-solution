[600.non-negative-integers-without-consecutive-ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)  

Given a positive integer n, find the number of **non-negative** integers less than or equal to n, whose binary representations do NOT contain **consecutive ones**.

**Example 1:**  

**Input:** 5
**Output:** 5
**Explanation:** 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 

**Note:** 1 <= n <= 109  



**Solution:**  

```cpp
class Solution {
public:
    int findIntegers(int num) {
        string s;
        while(num > 0){
            s += (num & 1) ? '1' : '0';
            num >>= 1;
        }
        int n = s.size();
        int z[n] = {0} ,o[n] = {0};
        z[0] = o[0] = 1;
        for(int i = 1; i < n; ++i){
            z[i] = z[i-1] + o[i-1];
            o[i] = z[i-1];
        }
        int ans = o[n-1] + z[n-1];
        n -= 2;
        while(n >= 0) {
            if(s[n] == s[n+1] && s[n] == '1') break;
            if(s[n] == s[n+1] && s[n] == '0') ans -= o[n];
            --n;
        }
        return ans;
    }
};
```
      