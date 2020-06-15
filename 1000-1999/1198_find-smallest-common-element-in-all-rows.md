[1198.find-smallest-common-element-in-all-rows](https://leetcode.com/problems/find-smallest-common-element-in-all-rows/)  

Given a matrix `mat` where every row is sorted in **increasing** order, return the **smallest common element** in all rows.

If there is no common element, return `-1`.

**Example 1:**

**Input:** mat = \[\[1,2,3,4,5\],\[2,4,5,8,10\],\[3,5,7,9,11\],\[1,3,5,7,9\]\]
**Output:** 5

**Constraints:**

*   `1 <= mat.length, mat[i].length <= 500`
*   `1 <= mat[i][j] <= 10^4`
*   `mat[i]` is sorted in increasing order.  



**Solution:**  

```cpp
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        if(mat.size() == 1) return mat[0][0];
        map<int, int> m;
        for(auto n : mat[0]) {
            ++m[n];
        }
        for(int i = 1; i < mat.size(); ++i) {
            for(auto n : mat[i])
                ++m[n];
        }
        for(auto &it  : m) {
            if(it.second == mat.size())
                return it.first;
        }
        return -1;
    }
};
```
      