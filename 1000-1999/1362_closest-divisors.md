[1362.closest-divisors](https://leetcode.com/problems/closest-divisors/)  

Given an integer `num`, find the closest two integers in absolute difference whose product equals `num + 1` or `num + 2`.

Return the two integers in any order.

**Example 1:**

**Input:** num = 8
**Output:** \[3,3\]
**Explanation:** For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.

**Example 2:**

**Input:** num = 123
**Output:** \[5,25\]

**Example 3:**

**Input:** num = 999
**Output:** \[40,25\]

**Constraints:**

*   `1 <= num <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int sq = sqrt(num + 2);
        vector<int> ans;
        int diff = INT_MAX;
        for(int i = 1; i <= sq; ++i) {
            if( (num + 1) % i == 0 ){
                int x = (num+1) / i;
                if(abs(x - i) < diff){
                    ans = {i, x};
                    diff = abs(x - i);
                }
            }
            if( (num + 2) % i == 0 ){
                int x = (num+2) / i;
                if(abs(x - i) < diff){
                    ans = {i, x};
                    diff = abs(x - i);
                }
            }
                
        }
        return ans;
    }
};
```
      