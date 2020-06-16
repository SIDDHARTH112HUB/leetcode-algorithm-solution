[764.largest-plus-sign](https://leetcode.com/problems/largest-plus-sign/)  

In a 2D `grid` from (0, 0) to (N-1, N-1), every cell contains a `1`, except those cells in the given list `mines` which are `0`. What is the largest axis-aligned plus sign of `1`s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "_axis-aligned plus sign of `1`s_ of order **k**" has some center `grid[x][y] = 1` along with 4 arms of length `k-1` going up, down, left, and right, and made of `1`s. This is demonstrated in the diagrams below. Note that there could be `0`s or `1`s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.

**Examples of Axis-Aligned Plus Signs of Order k:**  

  
Order 1:
  
000
  
0**1**0
  
000
  

  
Order 2:
  
00000
  
00**1**00
  
0**111**0
  
00**1**00
  
00000
  

  
Order 3:
  
0000000
  
000**1**000
  
000**1**000
  
0**11111**0
  
000**1**000
  
000**1**000
  
0000000
  

**Example 1:**  

  
**Input:** N = 5, mines = \[\[4, 2\]\]
  
**Output:** 2
  
**Explanation:**
  
11111
  
11111
  
1**1**111
  
**111**11
  
1**1**011
  
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
  

**Example 2:**  

  
**Input:** N = 2, mines = \[\]
  
**Output:** 1
  
**Explanation:**
  
There is no plus sign of order 2, but there is of order 1.
  

**Example 3:**  

  
**Input:** N = 1, mines = \[\[0, 0\]\]
  
**Output:** 0
  
**Explanation:**
  
There is no plus sign, so return 0.
  

**Note:**  

1.  `N` will be an integer in the range `[1, 500]`.
2.  `mines` will have length at most `5000`.
3.  `mines[i]` will be length 2 and consist of integers in the range `[0, N-1]`.
4.  _(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)_  



**Solution:**  

```cpp
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mine) {
        //vector<int> v = vector<int>(N, 1);
        vector< vector<int> > mines(N, vector<int>(N, 1));
        for( auto &m : mine){
            mines[m[0]][m[1]] = 0;
        }
        if( N == 1 ){
            if( mines[0][0] == 1) return 1;
            return 0;
        }
        if( N== 2){
            if( mines[0][0] == 1 ) return 1;
            if( mines[0][1] == 1 ) return 1;
            if( mines[1][0] == 1 ) return 1;
            if( mines[1][1] == 1 ) return 1;
            return 0;
        }
        
        int X = mines.size();
        int Y = mines[0].size();
        int maxOrder = 1;
        int order = 0;
       // printf("1 \n");
        for( int n = 1; n<=N/2;n++){
            for( int col = n; col<N-n; col++){
                order = checkMine(mines, N, N , n, col);
                if( order > maxOrder)
                    maxOrder = order;
                if( order == n+1 )
                    break;
             //   printf("2 \n");
                order = checkMine(mines, N, N , N-n-1, col);
                
                if( order > maxOrder)
                    maxOrder = order;
                if( order == n+1)
                    break;
                
                order = checkMine(mines, N, N , col, n);
                if( order > maxOrder)
                    maxOrder = order;
                if( order == n+1 )
                    break;
                
                order = checkMine(mines, N, N ,  col, N-n-1);
                
                if( order > maxOrder)
                    maxOrder = order;
                if( order == n+1)
                    break;
            }
          //  printf("3 \n");
            
        }
        return maxOrder;
    }
    int checkMine(vector< vector<int> > &mines, int X, int Y, int x, int y){
        int order = 1;
        //printf("5 %d %d %d \n", x, y, mines[x][y]);
        if( mines[x][y] != 1) return 0;
        //printf("4 \n");
        for( int i = 1; i<500;i++){
            if( x-i<0 || y-i<0 || x+i >=X || y+i >=Y)
                break;
            if( mines[x-i][y]==1 && mines[x+i][y]==1 && mines[x][y-i]==1 && mines[x][y+i]==1 )
                order = i+1;
            else
                break;
          //  printf("6 \n");
        }
        return order;
    }
};
```
      