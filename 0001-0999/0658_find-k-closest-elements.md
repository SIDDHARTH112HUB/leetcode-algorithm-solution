[658.find-k-closest-elements](https://leetcode.com/problems/find-k-closest-elements/)  

Given a sorted array `arr`, two integers `k` and `x`, find the `k` closest elements to `x` in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

**Example 1:**

**Input:** arr = \[1,2,3,4,5\], k = 4, x = 3
**Output:** \[1,2,3,4\]

**Example 2:**

**Input:** arr = \[1,2,3,4,5\], k = 4, x = -1
**Output:** \[1,2,3,4\]

**Constraints:**

*   `1 <= k <= arr.length`
*   `1 <= arr.length <= 10^4`
*   Absolute value of elements in the array and `x` will not exceed 104  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0, j = arr.size() - 1;
        while(j - i >= k) {
            if(abs(arr[j] - x) >= abs(arr[i] - x))
                --j;
            else
                ++i;
        }
        return vector<int>(arr.begin()+i, arr.begin() + j + 1);
    }
};
```
      