[240.search-a-2d-matrix-ii](https://leetcode.com/problems/search-a-2d-matrix-ii/)  

Write an efficient algorithm that searches for a value in an _m_ x _n_ matrix. This matrix has the following properties:

*   Integers in each row are sorted in ascending from left to right.
*   Integers in each column are sorted in ascending from top to bottom.

**Example:**

Consider the following matrix:

  
\[
  
  \[1,   4,  7, 11, 15\],
  
  \[2,   5,  8, 12, 19\],
  
  \[3,   6,  9, 16, 22\],
  
  \[10, 13, 14, 17, 24\],
  
  \[18, 21, 23, 26, 30\]
  
\]
  

Given target = `5`, return `true`.

Given target = `20`, return `false`.  



**Solution:**  

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int i = 0, j = matrix[0].size()-1;
        while( i < matrix.size() && j >= 0) {
            int n = matrix[i][j];
            if(n == target)
                return true;
            else if(n > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
```
      