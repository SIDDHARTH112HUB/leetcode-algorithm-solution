[483.smallest-good-base](https://leetcode.com/problems/smallest-good-base/)  

For an integer n, we call k>=2 a _**good base**_ of n, if all digits of n base k are 1.

Now given a string representing n, you should return the smallest good base of n in string format.

**Example 1:**

**Input:** "13"
**Output:** "3"
**Explanation:** 13 base 3 is 111.

**Example 2:**

**Input:** "4681"
**Output:** "8"
**Explanation:** 4681 base 8 is 11111.

**Example 3:**

**Input:** "1000000000000000000"
**Output:** "999999999999999999"
**Explanation:** 1000000000000000000 base 999999999999999999 is 11.

**Note:**

1.  The range of n is \[3, 10^18\].
2.  The string representing n is always valid and will not have leading zeros.  



**Solution:**  

```cpp
class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stol(n);
        long long l = 2, r = num - 1;
        long long m = log(num + 1) / log(2);
        for(long long i = m; i >= 2; --i) {
            long long l = 2;
            long long r = pow(num, 1.0 / (i - 1)) + 1;
            while(l < r) {
                long long mid = l + (r - l) / 2, sum = 0;
                for(int j = 0; j < i;++j) {
                    sum = sum * mid + 1;
                }
                if (sum == num)
                    return to_string(mid);
                if(sum > num)
                    r = mid;
                else
                    l = mid + 1;
            }
            
        }
        return to_string(num - 1);
    }
};
```
      