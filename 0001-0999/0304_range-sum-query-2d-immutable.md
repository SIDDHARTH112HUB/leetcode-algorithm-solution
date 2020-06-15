[304.range-sum-query-2d-immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/)  

Given a 2D matrix _matrix_, find the sum of the elements inside the rectangle defined by its upper left corner (_row_1, _col_1) and lower right corner (_row_2, _col_2).

![Range Sum Query 2D](/static/images/courses/range_sum_query_2d.png)  
The above rectangle (with the red border) is defined by (row1, col1) = **(2, 1)** and (row2, col2) = **(4, 3)**, which contains sum = **8**.

**Example:**  

Given matrix = \[
  \[3, 0, 1, 4, 2\],
  \[5, 6, 3, 2, 1\],
  \[1, 2, 0, 1, 5\],
  \[4, 1, 0, 1, 7\],
  \[1, 0, 3, 0, 5\]
\]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

**Note:**  

1.  You may assume that the matrix does not change.
2.  There are many calls to _sumRegion_ function.
3.  You may assume that _row_1 ≤ _row_2 and _col_1 ≤ _col_2.  



**Solution:**  

```cpp
class NumMatrix {
public:
    vector<vector<int> > m;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix;
        for(int i = 0; i < m.size(); ++i)
            for(int j = 0; j < m[i].size(); ++j)
                m[i][j] = m[i][j] + (i ? m[i - 1][j] : 0) + (j ? m[i][j-1] : 0) - (i && j ? m[i-1][j-1] : 0);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m[row2][col2] - (row1 ? m[row1-1][col2]: 0) - (col1? m[row2][col1-1] : 0) + (row1 && col1 ? m[row1-1][col1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```
      