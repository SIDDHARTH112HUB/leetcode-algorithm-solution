[782.transform-to-chessboard](https://leetcode.com/problems/transform-to-chessboard/)  

An N x N `board` contains only `0`s and `1`s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.

What is the minimum number of moves to transform the board into a "chessboard" - a board where no `0`s and no `1`s are 4-directionally adjacent? If the task is impossible, return -1.

  
**Examples:**
  
**Input:** board = \[\[0,1,1,0\],\[0,1,1,0\],\[1,0,0,1\],\[1,0,0,1\]\]
  
**Output:** 2
  
**Explanation:**
  
One potential sequence of moves is shown below, from left to right:
  

  
0110     1010     1010
  
0110 --> 1010 --> 0101
  
1001     0101     1010
  
1001     0101     0101
  

  
The first move swaps the first and second column.
  
The second move swaps the second and third row.
  

  

  
**Input:** board = \[\[0, 1\], \[1, 0\]\]
  
**Output:** 0
  
**Explanation:**
  
Also note that the board with 0 in the top left corner,
  
01
  
10
  

  
is also a valid chessboard.
  

  
**Input:** board = \[\[1, 0\], \[1, 0\]\]
  
**Output:** -1
  
**Explanation:**
  
No matter what sequence of moves you make, you cannot end with a valid chessboard.
  

**Note:**

*   `board` will have the same number of rows and columns, a number in the range `[2, 30]`.
*   `board[i][j]` will be only `0`s or `1`s.  



**Solution:**  

```cpp
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int N = board.size();
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j]) return -1;
            }
        }
        int rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;
        for(int i = 0; i < board.size(); ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowDiff += (board[i][0] == i % 2);
            colDiff += (board[0][i] == i % 2);
        }
        if(rowSum > (N + 1) / 2 || rowSum < N / 2) return -1;
        if(colSum > (N + 1) / 2 || colSum < N / 2) return -1;
        if(N % 2) {
            if (rowDiff % 2)rowDiff = N - rowDiff;
            if (colDiff % 2)colDiff = N - colDiff;
        }else{
            rowDiff = min(N - rowDiff, rowDiff);
            colDiff = min(N - colDiff, colDiff);
        }
        return (rowDiff + colDiff)/2;
    }
};
```
      