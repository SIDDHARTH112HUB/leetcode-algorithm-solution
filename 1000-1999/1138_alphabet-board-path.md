[1138.alphabet-board-path](https://leetcode.com/problems/alphabet-board-path/)  

On an alphabet board, we start at position `(0, 0)`, corresponding to character `board[0][0]`.

Here, `board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]`, as shown in the diagram below.

![](https://assets.leetcode.com/uploads/2019/07/28/azboard.png)

We may make the following moves:

*   `'U'` moves our position up one row, if the position exists on the board;
*   `'D'` moves our position down one row, if the position exists on the board;
*   `'L'` moves our position left one column, if the position exists on the board;
*   `'R'` moves our position right one column, if the position exists on the board;
*   `'!'` adds the character `board[r][c]` at our current position `(r, c)` to the answer.

(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to `target` in the minimum number of moves.  You may return any path that does so.

**Example 1:**

**Input:** target = "leet"
**Output:** "DDR!UURRR!!DDD!"

**Example 2:**

**Input:** target = "code"
**Output:** "RR!DDRR!UUL!R!"

**Constraints:**

*   `1 <= target.length <= 100`
*   `target` consists only of English lowercase letters.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    pair<int, int> getPos(char c) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if( board[i][j] == c)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
    string alphabetBoardPath(string target) {
        pair<int, int> p = { 0,  0};
        string ans ="";
        for( auto ch : target){
            auto next = getPos(ch);
            if( next == p){
                ans.push_back('!');
                continue;
            }
            
            if(ch == 'z'){
                int dy = next.second - p.second;
                char c = 'R';
                if( dy <  0)  c = 'L';
                for(int i = 0; i < abs(dy); ++i)
                    ans.push_back(c);
                    int dx = next.first - p.first;
                c = 'D';
                if(dx < 0) c = 'U';
                for(int i = 0; i < abs(dx); ++i)
                    ans.push_back(c);
            }else {
                int dx = next.first - p.first;
                char c = 'D';
                if(dx < 0) c = 'U';
                for(int i = 0; i < abs(dx); ++i)
                    ans.push_back(c);
                int dy = next.second - p.second;
                c = 'R';
                if( dy <  0)  c = 'L';
                for(int i = 0; i < abs(dy); ++i)
                    ans.push_back(c);
            }
            ans.push_back('!');
            
            p = next;
        }
        return ans;
    }
    
};
```
      