[1228.missing-number-in-arithmetic-progression](https://leetcode.com/problems/missing-number-in-arithmetic-progression/)  

In some array `arr`, the values were in arithmetic progression: the values `arr[i+1] - arr[i]` are all equal for every `0 <= i < arr.length - 1`.

Then, a value from `arr` was removed that **was not the first or last value in the array**.

Return the removed value.

**Example 1:**

**Input:** arr = \[5,7,11,13\]
**Output:** 9
**Explanation:** The previous array was \[5,7,**9**,11,13\].

**Example 2:**

**Input:** arr = \[15,13,12\]
**Output:** 14
**Explanation:** The previous array was \[15,**14**,13,12\].

**Constraints:**

*   `3 <= arr.length <= 1000`
*   `0 <= arr[i] <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int d1 = arr[1] - arr[0];
        int d2 = arr.back() - arr[arr.size()-2];
        if(abs(d1) > abs(d2)) d1 = d2;
        for(int i = 1; i < arr.size(); ++i) {
            if(arr[i] - arr[i-1] != d1) {
                return arr[i] - d1;
            }
        }
        return 0;
    }
};
```
      