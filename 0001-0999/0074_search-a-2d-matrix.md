[74.search-a-2d-matrix](https://leetcode.com/problems/search-a-2d-matrix/)  

Write an efficient algorithm that searches for a value in an _m_ x _n_ matrix. This matrix has the following properties:

*   Integers in each row are sorted from left to right.
*   The first integer of each row is greater than the last integer of the previous row.

**Example 1:**

  
**Input:**
  
matrix = \[
  
  \[1,   3,  5,  7\],
  
  \[10, 11, 16, 20\],
  
  \[23, 30, 34, 50\]
  
\]
  
target = 3
  
**Output:** true
  

**Example 2:**

  
**Input:**
  
matrix = \[
  
  \[1,   3,  5,  7\],
  
  \[10, 11, 16, 20\],
  
  \[23, 30, 34, 50\]
  
\]
  
target = 13
  
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.size() == 0 ) return 0;
        if( matrix[0].size() == 0 ) return 0;
        
        int left = 0, top = 0, right = matrix[0].size()-1, bottom = matrix.size()-1, mid;
        while(top <= bottom ){
            mid = ( top + bottom ) / 2;
            if( matrix[mid][0] <= target && matrix[mid][right] >= target)
                break;
            if( matrix[mid][0] < target)
                top = mid+1;
            else
                bottom = mid - 1;
        }
        if( top > bottom ) return false;
        while( left <= right ){
            int row_mid = (left+right ) / 2;
            if( matrix[mid][row_mid] == target)
                return true;
            if( matrix[mid][row_mid] < target )
                left = row_mid+1;
            else
                right = row_mid-1;
        }
        return false;
    }
};
```
      