[289.game-of-life](https://leetcode.com/problems/game-of-life/)  

According to the [Wikipedia's article](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life): "The **Game of Life**, also known simply as **Life**, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a _board_ with _m_ by _n_ cells, each cell has an initial state _live_ (1) or _dead_ (0). Each cell interacts with its [eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1.  Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2.  Any live cell with two or three live neighbors lives on to the next generation.
3.  Any live cell with more than three live neighbors dies, as if by over-population..
4.  Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

**Example:**

  
**Input:** \[
  
  \[0,1,0\],
  
  \[0,0,1\],
  
  \[1,1,1\],
  
  \[0,0,0\]
  
\]
  
**Output:** \[
  
  \[0,0,0\],
  
  \[1,0,1\],
  
  \[0,1,1\],
  
  \[0,1,0\]
  
\]
  

**Follow up**:

1.  Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
2.  In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?  



**Solution:**  

```cpp
class Solution {
public:
    int newState(vector<vector<int>>& board, int x, int y){
        int m = board.size();
        int n = board[0].size();
        int state = (board[x][y] & 1) ;
        int d[9] = { 1,0,-1,0,1,1,-1,-1,1};
        int live = 0, die = 0;
        for( int i = 0; i<= 7; i++){
            int nx = x - d[i];
            int ny = y - d[i+1];
            if( nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            live += (board[nx][ny] & 1);
            die += ( (board[nx][ny] & 1) == 0? 1:0);
        }
        if( state == 0 && live == 3 )
            return 1;
        if( state == 1 ){
            if( live <  2)  return 0;
            if( live == 2 || live == 3 ) return state;
            if( live > 3 ) return 0;
        }
        return state;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for( int i = 0; i<m ; i++){ 
            for( int j = 0; j<n; j++){
                board[i][j]  |= (newState(board, i, j) << 1);
            }
        }
        for( int i = 0; i<m ; i++){ 
            for( int j = 0; j<n; j++){
                board[i][j] = board[i][j]>>1;
            }
        }
    }
};
```
      