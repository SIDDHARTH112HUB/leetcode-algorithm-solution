[1299.replace-elements-with-greatest-element-on-right-side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)  

Given an array `arr`, replace every element in that array with the greatest element among the elements to its right, and replace the last element with `-1`.

After doing so, return the array.

**Example 1:**

**Input:** arr = \[17,18,5,4,6,1\]
  
**Output:** \[18,6,6,6,1,-1\]
  

**Constraints:**

*   `1 <= arr.length <= 10^4`
*   `1 <= arr[i] <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx = arr.back();
        arr[arr.size()-1] = -1;
        for(int i = arr.size()-2; i >=0; --i) {
            int src = arr[i];
            arr[i] = mx;
            mx = max(src, mx);
        }
        return arr;
    }
};
```
      