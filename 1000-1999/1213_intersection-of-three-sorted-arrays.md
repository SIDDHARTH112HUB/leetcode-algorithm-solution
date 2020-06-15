[1213.intersection-of-three-sorted-arrays](https://leetcode.com/problems/intersection-of-three-sorted-arrays/)  

Given three integer arrays `arr1`, `arr2` and `arr3` **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

**Example 1:**

**Input:** arr1 = \[1,2,3,4,5\], arr2 = \[1,2,5,7,9\], arr3 = \[1,3,4,5,8\]
**Output:** \[1,5\]
**Explanation:** Only 1 and 5 appeared in the three arrays.

**Constraints:**

*   `1 <= arr1.length, arr2.length, arr3.length <= 1000`
*   `1 <= arr1[i], arr2[i], arr3[i] <= 2000`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> m1, m2, m3;
        for(auto n : arr1)
            ++m1[n];
        for(auto n : arr2)
            ++m2[n];
        for(auto n : arr3)
            ++m3[n];
        vector<int> ans;
        for(auto it : m1) {
            if(m2[it.first] > 0 && m3[it.first] > 0)
                ans.push_back(it.first);
        }
        return ans;
    }
};
```
      