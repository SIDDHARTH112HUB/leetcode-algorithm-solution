[1287.element-appearing-more-than-25-in-sorted-array](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/)  

Given an integer array **sorted** in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.

**Example 1:**

**Input:** arr = \[1,2,2,6,6,6,6,7,10\]
**Output:** 6

**Constraints:**

*   `1 <= arr.length <= 10^4`
*   `0 <= arr[i] <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> m;
        for(auto n : arr)
            ++m[n];
        for(auto it : m) {
            if(it.second > arr.size() / 4)
                return it.first;
        }
        return 0;
    }
};
```
      