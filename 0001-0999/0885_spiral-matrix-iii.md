[885.spiral-matrix-iii](https://leetcode.com/problems/spiral-matrix-iii/)  

On a 2 dimensional grid with `R` rows and `C` columns, we start at `(r0, c0)` facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid. 

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 

Eventually, we reach all `R * C` spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.

**Example 1:**

  
**Input:** R = 1, C = 4, r0 = 0, c0 = 0
  
**Output:** \[\[0,0\],\[0,1\],\[0,2\],\[0,3\]\]
  

  
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/24/example_1.png)
  

**Example 2:**

  
**Input:** R = 5, C = 6, r0 = 1, c0 = 4
  
**Output:** \[\[1,4\],\[1,5\],\[2,5\],\[2,4\],\[2,3\],\[1,3\],\[0,3\],\[0,4\],\[0,5\],\[3,5\],\[3,4\],\[3,3\],\[3,2\],\[2,2\],\[1,2\],\[0,2\],\[4,5\],\[4,4\],\[4,3\],\[4,2\],\[4,1\],\[3,1\],\[2,1\],\[1,1\],\[0,1\],\[4,0\],\[3,0\],\[2,0\],\[1,0\],\[0,0\]\]
  

  
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/24/example_2.png)
  

**Note:**

1.  `1 <= R <= 100`
2.  `1 <= C <= 100`
3.  `0 <= r0 < R`
4.  `0 <= c0 < C`  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int total = R*C;
        int dx[4] = { 0 , 1, 0, -1};
        int dy[4] = { 1 , 0, -1, 0};
        int cnt = 0;
        vector<vector<int> > ans;
        ans.push_back({r0, c0});
        while(total > ans.size() ){
            int step = cnt/2+1;
            for( int i = 1; i<=step;i++){
                r0 += dx[cnt%4];
                c0 += dy[cnt%4];
                if( r0 >= 0 && c0 >= 0 && r0 < R && c0 <C )
                    ans.push_back({r0,c0});
            }
            cnt++;
        }
        return ans;
    }
};
```
      