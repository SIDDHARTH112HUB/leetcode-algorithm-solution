[54.spiral-matrix](https://leetcode.com/problems/spiral-matrix/)  

Given a matrix of _m_ x _n_ elements (_m_ rows, _n_ columns), return all elements of the matrix in spiral order.

**Example 1:**

  
**Input:**
  
\[
  
 \[ 1, 2, 3 \],
  
 \[ 4, 5, 6 \],
  
 \[ 7, 8, 9 \]
  
\]
  
**Output:** \[1,2,3,6,9,8,7,4,5\]
  

**Example 2:**

  
**Input:**
  
\[
  
  \[1, 2, 3, 4\],
  
  \[5, 6, 7, 8\],
  
  \[9,10,11,12\]
  
\]
  
**Output:** \[1,2,3,4,8,12,11,10,9,5,6,7\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if( m == 0 ) return ans;
        int n = matrix[0].size();
        if( n == 0 ) return ans;
        int x = 0, y =0;
        int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
        int dir = 0;
        while(matrix[x][y]> INT_MIN){
            ans.push_back(matrix[x][y]);
            matrix[x][y] = INT_MIN;
            int nx = dx[dir%4] + x;
            int ny = dy[dir%4] + y;
            if( nx < 0 || ny < 0 || nx >=m || ny >=n || matrix[nx][ny] == INT_MIN ){
                ++dir;
            }
            nx = dx[dir%4] + x;
            ny = dy[dir%4] + y;
            if( nx < 0 || ny < 0 || nx >=m || ny >=n || matrix[nx][ny] == INT_MIN ){
                break;
            }
            x = nx;
            y = ny;
        }
        return ans;
    }
};
```
      