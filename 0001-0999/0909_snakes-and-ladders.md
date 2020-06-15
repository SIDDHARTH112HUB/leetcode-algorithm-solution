[909.snakes-and-ladders](https://leetcode.com/problems/snakes-and-ladders/)  

On an N x N `board`, the numbers from `1` to `N*N` are written _boustrophedonically_ **starting from the bottom left of the board**, and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:

![](https://assets.leetcode.com/uploads/2018/09/23/snakes.png)

You start on square `1` of the board (which is always in the last row and first column).  Each move, starting from square `x`, consists of the following:

*   You choose a destination square `S` with number `x+1`, `x+2`, `x+3`, `x+4`, `x+5`, or `x+6`, provided this number is `<= N*N`.
    *   (This choice simulates the result of a standard 6-sided die roll: ie., there are always **at most 6 destinations, regardless of the size of the board**.)
*   If `S` has a snake or ladder, you move to the destination of that snake or ladder.  Otherwise, you move to `S`.

A board square on row `r` and column `c` has a "snake or ladder" if `board[r][c] != -1`.  The destination of that snake or ladder is `board[r][c]`.

Note that you only take a snake or ladder at most once per move: if the destination to a snake or ladder is the start of another snake or ladder, you do **not** continue moving.  (For example, if the board is \`\[\[4,-1\],\[-1,3\]\]\`, and on the first move your destination square is \`2\`, then you finish your first move at \`3\`, because you do **not** continue moving to \`4\`.)

Return the least number of moves required to reach square N\*N.  If it is not possible, return `-1`.

**Example 1:**

**Input:** \[
\[-1,-1,-1,-1,-1,-1\],
\[-1,-1,-1,-1,-1,-1\],
\[-1,-1,-1,-1,-1,-1\],
\[-1,35,-1,-1,13,-1\],
\[-1,-1,-1,-1,-1,-1\],
\[-1,15,-1,-1,-1,-1\]\]
**Output:** 4
**Explanation:** 
At the beginning, you start at square 1 \[at row 5, column 0\].
You decide to move to square 2, and must take the ladder to square 15.
You then decide to move to square 17 (row 3, column 5), and must take the snake to square 13.
You then decide to move to square 14, and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
It can be shown that you need at least 4 moves to reach the N\*N-th square, so the answer is 4.

**Note:**

1.  `2 <= board.length = board[0].length <= 20`
2.  `board[i][j]` is between `1` and `N*N` or is equal to `-1`.
3.  The board square with number `1` has no snake or ladder.
4.  The board square with number `N*N` has no snake or ladder.  



**Solution:**  

```cpp
class Solution {
public:
    int N;
    pair<int, int> getPos(int pos){
        pos -= 1;
        return {pos / N, pos%N};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        N = board.size();
        for( int i = 1; i<N; i+=2){
            reverse(board[i].begin(), board[i].end());
        }
        int end = N*N;
        queue<int> q;
        q.push(1);
        unordered_set<int> visited;
        int steps = 0;
        while( q.size() > 0 ){
            int size = q.size();
            while( size-- > 0 ){
                int idx = q.front();
                q.pop();
                if( idx == end ) return steps;
                for( int i = 1; i<= 6; i++){
                    if( idx + i > end ) continue;
                    int new_idx = idx + i;
                    auto pos = getPos(idx+i);
                    int val = board[pos.first][pos.second];
                    if( val > 0 )
                        new_idx = val;
                    if( visited.count(new_idx) ) continue;
                    q.push(new_idx);
                    visited.insert(new_idx);    
                }
            }
            steps++;
        }
        return -1;
    }
};
```
      