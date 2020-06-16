[73.set-matrix-zeroes](https://leetcode.com/problems/set-matrix-zeroes/)  

Given a _m_ x _n_ matrix, if an element is 0, set its entire row and column to 0. Do it [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm).

**Example 1:**

  
**Input:** 
  
\[
  
  \[1,1,1\],
  
  \[1,0,1\],
  
  \[1,1,1\]
  
\]
  
**Output:** 
  
\[
  
  \[1,0,1\],
  
  \[0,0,0\],
  
  \[1,0,1\]
  
\]
  

**Example 2:**

  
**Input:** 
  
\[
  
  \[0,1,2,0\],
  
  \[3,4,5,2\],
  
  \[1,3,1,5\]
  
\]
  
**Output:** 
  
\[
  
  \[0,0,0,0\],
  
  \[0,4,5,0\],
  
  \[0,3,1,0\]
  
\]
  

**Follow up:**

*   A straight forward solution using O(_m__n_) space is probably a bad idea.
*   A simple improvement uses O(_m_ + _n_) space, but still not the best solution.
*   Could you devise a constant space solution?  



**Solution:**  

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool row0_zero = false;
        bool column0_zero = false;
        bool lastrow_zero = false;
        int ROW = matrix.size();
        int COL = matrix[0].size();
        for(int i = 0; i < COL; ++i)  
            if (matrix[0][i] == 0)  
            {  
                row0_zero = true;  
                break;  
            }  
        for(int i = 0; i < ROW; ++i)  
            if (matrix[i][0] == 0)  
            {  
                column0_zero = true;  
                break;  
            }  
            
        for( int i = 0; i <matrix.size(); i++)
        {
            vector<int>& row = matrix[i];
            for( int j = 0; j<row.size(); j++ )
            {
                if( row[j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < ROW; ++i)  
            if (matrix[i][0] == 0)  
                for(int j = 1; j < COL; ++j)  
                    matrix[i][j] = 0;  
          
        for(int i = 1; i < COL; ++i)  
            if (matrix[0][i] == 0)  
                for(int j = 1; j < ROW; ++j)  
                    matrix[j][i] = 0;  
        if (row0_zero)  
            fill(begin(matrix[0]), end(matrix[0]), 0);  
        if (column0_zero)  
            for(int i = 0; i < ROW; ++i)  
                matrix[i][0] = 0;  
    }
};
```
      