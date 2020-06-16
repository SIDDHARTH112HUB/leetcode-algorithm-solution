[794.valid-tic-tac-toe-state](https://leetcode.com/problems/valid-tic-tac-toe-state/)  

A Tic-Tac-Toe board is given as a string array `board`. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The `board` is a 3 x 3 array, and consists of characters `" "`, `"X"`, and `"O"`.  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

*   Players take turns placing characters into empty squares (" ").
*   The first player always places "X" characters, while the second player always places "O" characters.
*   "X" and "O" characters are always placed into empty squares, never filled ones.
*   The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
*   The game also ends if all squares are non-empty.
*   No more moves can be played if the game is over.

  
**Example 1:**
  
**Input:** board = \["O  ", "   ", "   "\]
  
**Output:** false
  
**Explanation:** The first player always plays "X".
  

  
**Example 2:**
  
**Input:** board = \["XOX", " X ", "   "\]
  
**Output:** false
  
**Explanation:** Players take turns making moves.
  

  
**Example 3:**
  
**Input:** board = \["XXX", "   ", "OOO"\]
  
**Output:** false
  

  
**Example 4:**
  
**Input:** board = \["XOX", "O O", "XOX"\]
  
**Output:** true
  

**Note:**

*   `board` is a length-3 array of strings, where each string `board[i]` has length 3.
*   Each `board[i][j]` is a character in the set `{" ", "X", "O"}`.  



**Solution:**  

```cpp
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int X = 0, O=0;
        for( auto &b : board){
            for( char c : b){
                if( c == 'X')
                    X++;
                else if( c== 'O')
                    O++;
            }
        }
        if( O > X)
            return false;
        if( abs(O-X)>1 )
            return false;
        bool O_win = false;
        bool X_win = false;
        for( int i =0; i<3; i++){
            if( board[i][0] == board[i][1] && board[i][0] == board[i][2] ){
                if( board[i][0] == 'X'){
                    X_win = true;
                }
                else if( board[i][0] == 'O')
                    O_win = true;
                    
            }
            if( board[0][i] == board[1][i] && board[1][i] == board[2][i] ){
                if( board[0][i] == 'X'){
                    X_win = true;
                }
                else if( board[0][i] == 'O')
                    O_win = true;
                    
            }
                
        }
        if( board[0][0] == board[1][1] && board[1][1] == board[2][2] ){
                if( board[1][1] == 'X'){
                    X_win = true;
                }
                else if( board[1][1] == 'O')
                    O_win = true;
                    
        }
        if( board[0][2] == board[1][1] && board[1][1] == board[2][0] ){
                if( board[1][1] == 'X'){
                    X_win = true;
                }
                else if( board[1][1] == 'O')
                    O_win = true;
                    
        }
        if( X_win ==true && O_win==true)
            return false;
        if( X_win == true && abs( X - O) == 0 )
            return false;
        if( O_win == true && X > O )
            return false;
        return true;
    }
};
```
      