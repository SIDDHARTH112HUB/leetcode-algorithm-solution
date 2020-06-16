[773.sliding-puzzle](https://leetcode.com/problems/sliding-puzzle/)  

On a 2x3 `board`, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing `0` and a 4-directionally adjacent number and swapping it.

The state of the board is _solved_ if and only if the `board` is `[[1,2,3],[4,5,0]].`

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

**Examples:**

  
**Input:** board = \[\[1,2,3\],\[4,0,5\]\]
  
**Output:** 1
  
**Explanation:** Swap the 0 and the 5 in one move.
  

  
**Input:** board = \[\[1,2,3\],\[5,4,0\]\]
  
**Output:** -1
  
**Explanation:** No number of moves will make the board solved.
  

  
**Input:** board = \[\[4,1,2\],\[5,0,3\]\]
  
**Output:** 5
  
**Explanation:** 5 is the smallest number of moves that solves the board.
  
An example path:
  
After move 0: \[\[4,1,2\],\[5,0,3\]\]
  
After move 1: \[\[4,1,2\],\[0,5,3\]\]
  
After move 2: \[\[0,1,2\],\[4,5,3\]\]
  
After move 3: \[\[1,0,2\],\[4,5,3\]\]
  
After move 4: \[\[1,2,0\],\[4,5,3\]\]
  
After move 5: \[\[1,2,3\],\[4,5,0\]\]
  

  
**Input:** board = \[\[3,2,4\],\[1,5,0\]\]
  
**Output:** 14
  

**Note:**

*   `board` will be a 2 x 3 array as described above.
*   `board[i][j]` will be a permutation of `[0, 1, 2, 3, 4, 5]`.  



**Solution:**  

```cpp

class Solution {
public:
    int hash(vector<vector<int> > &b) {
        int mask = 0;
        for(int i = 0; i < b.size(); ++i)
            for(int j = 0; j < b[0].size(); ++j)
                mask |= (b[i][j] << ((i * 3 + j) * 4) );
        return mask;
    }
    pair<int, int> getZero(vector<vector<int> > &b) {
        for(int i = 0; i < b.size(); ++i)
            for(int j = 0; j < b[0].size(); ++j)
                if(b[i][j] == 0) return {i, j};
        return {-111, -111};
    }
    bool check(vector<vector<int> > &b) {
        return b[0][0] == 1 && b[0][1] == 2 && b[0][2] == 3 && b[1][0] == 4 && b[1][1] == 5 && b[1][2] == 0;
    }
    unordered_set<int> v;
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int> > > q;
        q.push(board);
        v.insert(hash(board));
        int step = 0;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size--) {
                auto &b = q.front();
                if(check(b)) return step;
                auto point = getZero(b);
                int x = point.first;
                int y = point.second;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + d[i];
                    int ny = y + d[i+1];
                    if(nx < 0 || ny < 0 || nx >= b.size() || ny >=b[0].size())
                        continue;
                    swap(b[x][y], b[nx][ny]);
                    int h = hash(b);
                    if(v.count(h) == 0){
                        q.push(b);
                        v.insert(h);
                    }
                    swap(b[x][y], b[nx][ny]);
                }
                q.pop();
            }
            ++step;
        }
        return -1;
    }
};
```
      