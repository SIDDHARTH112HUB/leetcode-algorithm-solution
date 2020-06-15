[1131.maximum-of-absolute-value-expression](https://leetcode.com/problems/maximum-of-absolute-value-expression/)  

Given two arrays of integers with equal lengths, return the maximum value of:

`|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|`

where the maximum is taken over all `0 <= i, j < arr1.length`.

**Example 1:**

**Input:** arr1 = \[1,2,3,4\], arr2 = \[-1,4,5,6\]
**Output:** 13

**Example 2:**

**Input:** arr1 = \[1,-2,-5,0,10\], arr2 = \[0,-2,-1,-7,-4\]
**Output:** 20

**Constraints:**

*   `2 <= arr1.length == arr2.length <= 40000`
*   `-10^6 <= arr1[i], arr2[i] <= 10^6`  



**Solution:**  

```cpp
class Solution {
public:
    int maxAbsValExpr(vector<int>& a1, vector<int>& a2) {
    
        /*res = a1[i] + a2[i]  - (a1[j] + a2[j] + j);
        res = a2[i] - a1[i] + (a1[j] - a2[j] - j);
        res = a1[i]- a2[i] - (a1[j] - a2[j] + j);
        res = -(a1[i] + a2[i]) + (a1[j] + a2[j] - j);
        */
        int b[4] = {0};
        int ans = 0;
        for(int i = 0; i < a1.size(); ++i) {
            int r1 = a1[i] + a2[i];
            int r2 = a1[i] - a2[i];
            if( i == 0){
                b[0] = r1 + i;
                b[1] = r2 - i;
                b[2] = r2 + i;
                b[3] = r1 - i;
                continue;
            }
            ans = max(ans, r1 - b[0] + i);
            ans = max(ans, -r2 + b[1] + i);
            ans = max(ans, r2 - b[2] + i);
            ans = max(ans, -r1 + b[3] + i);
            b[0] = min(b[0], r1 + i);
            b[1] = max(b[1], r2 - i);
            b[2] = min(b[2], r2 + i);
            b[3] = max(b[3], r1 - i);
        }
        return ans;
    }
};
```
      