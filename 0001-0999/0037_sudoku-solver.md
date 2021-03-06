[37.sudoku-solver](https://leetcode.com/problems/sudoku-solver/)  

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules**:

1.  Each of the digits `1-9` must occur exactly once in each row.
2.  Each of the digits `1-9` must occur exactly once in each column.
3.  Each of the the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.

Empty cells are indicated by the character `'.'`.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)  
A sudoku puzzle...

![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)  
...and its solution numbers marked in red.

**Note:**

*   The given board contain only digits `1-9` and the character `'.'`.
*   You may assume that the given Sudoku puzzle will have a single unique solution.
*   The given board size is always `9x9`.  



**Solution:**  

```cpp
class Solution {
public:
    bool check(vector<vector<char>>& board, char num, int row, int col ){
        for( int i = 0; i<9;i++ ){
            if( board[row][i] == num )
                return false;
            if( board[i][col] == num)
                return false;
            if( board[row/3*3 + i/3 ][col/3*3 +i%3] == num )
                return false;
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board, int i=0, int j = 0) {
        if(j == 9 ) return solveSudoku(board, i+1, 0);
        if(i == 9 ) return true;
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
        bool flag = false;
        for( char n = '1'; n<='9'; n++){
            if( check( board, n, i, j) ){
                flag = true;
                board[i][j] = n;
                bool res = solveSudoku(board, i, j+1);
                if( res )
                    return res;
                else
                    board[i][j] = '.';
            }
        }
        return false;
    }
};
```
      