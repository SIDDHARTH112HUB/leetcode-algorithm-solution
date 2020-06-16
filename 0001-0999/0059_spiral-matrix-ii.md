[59.spiral-matrix-ii](https://leetcode.com/problems/spiral-matrix-ii/)  

Given a positive integer _n_, generate a square matrix filled with elements from 1 to _n_2 in spiral order.

**Example:**

  
**Input:** 3
  
**Output:**
  
\[
  
 \[ 1, 2, 3 \],
  
 \[ 8, 9, 4 \],
  
 \[ 7, 6, 5 \]
  
\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
        int d = 0;
        vector<vector<int>> matrix( n, vector<int>(n, 0) );
        int X = n;
        int Y = n;
        int size = n*n;
        if( size == 0 ) return matrix;
        int cur_size = 0;
        int x = 0;
        int y = 0;
        
        int x_d = direction[d%4][0];
        int y_d = direction[d%4][1];
        int cnt = 1;
        while(cnt<=size){
            matrix[x][y] = cnt++;
            int tmp_x = x+x_d;
            int tmp_y = y+y_d;
            if( tmp_x < 0 || tmp_x>=matrix.size() || tmp_y<0 || tmp_y>=Y ){
                d++;
            }else if( matrix[tmp_x][tmp_y] != 0 ){
                d++;
            }
            x_d = direction[d%4][0];
            y_d = direction[d%4][1];
            x += x_d;
            y += y_d;
        }
        return matrix;
    }
};
```
      