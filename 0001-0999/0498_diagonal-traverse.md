[498.diagonal-traverse](https://leetcode.com/problems/diagonal-traverse/)  

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

**Example:**

**Input:**
\[
 \[ 1, 2, 3 \],
 \[ 4, 5, 6 \],
 \[ 7, 8, 9 \]
\]

**Output:**  \[1,2,4,7,5,3,6,8,9\]

**Explanation:**
![](https://assets.leetcode.com/uploads/2018/10/12/diagonal_traverse.png)

**Note:**

The total number of elements of the given matrix will not exceed 10,000.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int x = 0, y = 0;
        int dx = -1, dy = 1;
        int m = matrix.size();
        if(m <= 0) return {};
        int n = matrix[0].size();
        if(n <= 0) return {};
        vector<int> ans;
        while(ans.size() < m* n) {
            ans.push_back(matrix[x][y]);
            x += dx;
            y += dy;
            if(x >= m) { x = m - 1; y += 2; swap(dx, dy);}
            if(y >= n) { y = n - 1; x += 2; swap(dx, dy);}
            if(x < 0) { x = 0; swap(dx, dy);}
            if(y < 0) { y = 0; swap(dx, dy);}
        }
        return ans;
    }
};
```
      