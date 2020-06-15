[348.design-tic-tac-toe](https://leetcode.com/problems/design-tic-tac-toe/)  

Design a Tic-tac-toe game that is played between two players on a _n_ x _n_ grid.

You may assume the following rules:

1.  A move is guaranteed to be valid and is placed on an empty block.
2.  Once a winning condition is reached, no more moves is allowed.
3.  A player who succeeds in placing _n_ of their marks in a horizontal, vertical, or diagonal row wins the game.

**Example:**  

Given _n_ = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

**Follow up:**  
Could you do better than O(_n_2) per `move()` operation?  



**Solution:**  

```cpp
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, 0));   
    }

    int move(int row, int col, int player) {
        board[row][col] = player;
        int i = 0, j = 0, n = board.size();
        for (j = 1; j < n; ++j) {
            if (board[row][j] != board[row][j - 1]) break;
        }
        if (j == n) return player;
        for (i = 1; i < n; ++i) {
            if (board[i][col] != board[i - 1][col]) break;
        }
        if (i == n) return player;
        if (row == col) {
            for (i = 1; i < n; ++i) {
                if (board[i][i] != board[i - 1][i - 1]) break;
            }
            if (i == n) return player;
        }
        if (row + col == n - 1) {
            for (i = 1; i < n; ++i) {
                if (board[n - i - 1][i] != board[n - i][i - 1]) break;
            }
            if (i == n) return player;
        }
        return 0;
    }
    
private:
    vector<vector<int>> board;
};
```
      