[1118.number-of-days-in-a-month](https://leetcode.com/problems/number-of-days-in-a-month/)  

Given a year `Y` and a month `M`, return how many days there are in that month.

**Example 1:**

**Input:** Y = 1992, M = 7
**Output:** 31

**Example 2:**

**Input:** Y = 2000, M = 2
**Output:** 29

**Example 3:**

**Input:** Y = 1900, M = 2
**Output:** 28

**Note:**

1.  `1583 <= Y <= 2100`
2.  `1 <= M <= 12`  



**Solution:**  

```cpp
class Solution {
public:
    int numberOfDays(int Y, int M) {
        int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31 , 30, 31, 30, 31};
        if(( Y % 100 == 0 && Y % 400 == 0 )|| (Y % 100 != 0 && Y % 4 == 0) ){
            if(M == 2)
                return 29;
        }
        return m[M];
    }
};
```
      