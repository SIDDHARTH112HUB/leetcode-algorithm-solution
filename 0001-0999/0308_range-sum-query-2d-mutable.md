[308.range-sum-query-2d-mutable](https://leetcode.com/problems/range-sum-query-2d-mutable/)  

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
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10

**Note:**  

1.  The matrix is only modifiable by the _update_ function.
2.  You may assume the number of calls to _update_ and _sumRegion_ function is distributed evenly.
3.  You may assume that _row_1 ≤ _row_2 and _col_1 ≤ _col_2.  



**Solution:**  

```cpp
class NumMatrix {
public:
    vector<vector<int> > mat;
    vector<vector<int> > bit;
    int m;
    int n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0) return;
        n = matrix[0].size();
        mat.resize(m+1, vector<int>(n+1));
        bit.resize(m+1, vector<int>(n+1));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int d = val - mat[row+1][col+1];
        for(int i = row + 1; i <= m; i += i & -i) {
            for(int j = col + 1; j <=n; j += j & -j) {
                bit[i][j] += d;
            }
        }
        mat[row+1][col+1] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) + getSum(row1 - 1, col1 - 1) - getSum(row2, col1-1) - getSum(row1-1, col2);
    }
    
    int getSum(int row, int col) {
        int sum = 0;
        for(int i = row + 1; i > 0; i -= i & -i) {
            for(int j = col + 1; j > 0; j -= j & -j) {
                sum += bit[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
```
      