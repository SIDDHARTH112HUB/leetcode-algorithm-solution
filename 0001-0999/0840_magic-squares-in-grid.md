[840.magic-squares-in-grid](https://leetcode.com/problems/magic-squares-in-grid/)  

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers **from 1 to 9** such that each row, column, and both diagonals all have the same sum.

Given an `grid` of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

**Example 1:**

  
**Input:** \[\[4,3,8,4\],
  
        \[9,5,1,9\],
  
        \[2,7,6,2\]\]
  
**Output:** 1
  
**Explanation:** 
  
The following subgrid is a 3 x 3 magic square:
  
438
  
951
  
276
  

  
while this one is not:
  
384
  
519
  
762
  

  
In total, there is only one magic square inside the given grid.
  

**Note:**

1.  `1 <= grid.length <= 10`
2.  `1 <= grid[0].length <= 10`
3.  `0 <= grid[i][j] <= 15`  



**Solution:**  

```cpp
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        if( n < 3 ) return 0;
        int m = grid[0].size();
        if( m < 3 ) return 0;
        int ans = 0;
        int check[10] = {0};
        for( int i = 0;i < n-2; i++ ){
            for( int j = 0; j<m-2; j++ ){
                int sum = grid[i][j] + grid[i+1][j+1]+grid[i+2][j+2];
                int sum2 = grid[i+2][j] + grid[i+1][j+1]+grid[i][j+2];
                if( sum != sum2)
                    continue;
                bool flag = false;
                memset(check, 0, sizeof(int) *10);
                for( int k = 0; k<3;k ++){
                    
                    if (( grid[i+k][j] >9 || grid[i+k][j] < 1) || ( grid[i+k][j+1] >9 || grid[i+k][j+1] < 1) ||
                            ( grid[i+k][j+2] >9 || grid[i+k][j+2] < 1) ){
                        flag = true;
                        //printf("grid check i:%d j:%d \n", i, j );
                        break;
                    }
                    
                    if( check[grid[i+k][j]] || check[grid[i+k][j+1]] || check[grid[i+k][j+2]] ){
                        //printf(" check array i:%d j:%d \n", i, j );
                        flag = true;
                        break;
                    }else{
                        check[grid[i+k][j]] = 1;
                        check[grid[i+k][j+1]] =1;
                        check[grid[i+k][j+2]] =1;
                    }
                    int num = grid[i][j+k] + grid[i+1][j+k]+grid[i+2][j+k];
                    
                    if( num != sum ){
                        //printf(" check column i:%d j:%d \n", i, j );
                        flag = true;
                        break;
                    }
                    num = grid[i+k][j] + grid[i+k][j+1]+grid[i+k][j+2];
                    if( num != sum ){
                        //printf(" check row i:%d j:%d \n", i, j );
                        flag = true;
                        break;
                    }
                }
                if( !flag )
                    ans++;
            }
        }
        return ans;
    }
};
```
      