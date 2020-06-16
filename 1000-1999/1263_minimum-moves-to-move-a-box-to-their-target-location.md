[1263.minimum-moves-to-move-a-box-to-their-target-location](https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/)  

Storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.

The game is represented by a `grid` of size `m x n`, where each element is a wall, floor, or a box.

Your task is move the box `'B'` to the target position `'T'` under the following rules:

*   Player is represented by character `'S'` and can move up, down, left, right in the `grid` if it is a floor (empy cell).
*   Floor is represented by character `'.'` that means free cell to walk.
*   Wall is represented by character `'#'` that means obstacle  (impossible to walk there). 
*   There is only one box `'B'` and one target cell `'T'` in the `grid`.
*   The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a **push**.
*   The player cannot walk through the box.

Return the minimum number of **pushes** to move the box to the target. If there is no way to reach the target, return `-1`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/11/06/sample_1_1620.png)**

  
**Input:** grid = \[\["#","#","#","#","#","#"\],  
               \["#","T","#","#","#","#"\],  
               \["#",".",".","B",".","#"\],  
               \["#",".","#","#",".","#"\],  
               \["#",".",".",".","S","#"\],  
               \["#","#","#","#","#","#"\]\]  
**Output:** 3  
**Explanation:** We return only the number of times the box is pushed.

**Example 2:**

  
**Input:** grid = \[\["#","#","#","#","#","#"\],  
               \["#","T","#","#","#","#"\],  
               \["#",".",".","B",".","#"\],  
               \["#","#","#","#",".","#"\],  
               \["#",".",".",".","S","#"\],  
               \["#","#","#","#","#","#"\]\]  
**Output:** -1  

**Example 3:**

  
**Input:** grid = \[\["#","#","#","#","#","#"\],  
               \["#","T",".",".","#","#"\],  
               \["#",".","#","B",".","#"\],  
               \["#",".",".",".",".","#"\],  
               \["#",".",".",".","S","#"\],  
               \["#","#","#","#","#","#"\]\]  
**Output:** 5  
**Explanation:**  push the box down, left, left, up and up.  

**Example 4:**

  
**Input:** grid = \[\["#","#","#","#","#","#","#"\],  
               \["#","S","#",".","B","T","#"\],  
               \["#","#","#","#","#","#","#"\]\]  
**Output:** -1  

**Constraints:**

*   `m == grid.length`
*   `n == grid[i].length`
*   `1 <= m <= 20`
*   `1 <= n <= 20`
*   `grid` contains only characters `'.'`, `'#'`,  `'S'` , `'T'`, or `'B'`.
*   There is only one character `'S'`, `'B'` and `'T'` in the `grid`.  



**Solution:**  

```cpp
class Solution {
public:
    set<int> v;
    queue<int> q;
    int m;
    int n;
    int hash(int px, int py, int bx, int by) {
        return (px << 24) | (py << 16) | (bx << 8) | by;
    }
    void get(int h, int &px, int &py, int &bx, int &by) {
        px = (h >> 24) & 0xff;
        py = (h >> 16) & 0xff;
        bx = (h >> 8) & 0xff;
        by = h & 0xff;
    }
    void dfs(int px, int py, int bx, int by, set<pair<int, int> > &seen, vector<vector<char>>& grid) {
        if(px == bx && py == by ) return;
        if(px < 0 || py < 0 || px >= m || py >= n || grid[px][py] == '#') return;
        if(seen.count({px, py})) return;
        if((px == bx && abs(py - by) == 1) || (abs(px - bx) == 1 && py == by)) {
            int h = hash(px, py, bx, by);
            if(v.count(h) == 0){
                v.insert(h);
                q.push(h);
            }
        }
        seen.insert({px, py});
        dfs(px + 1, py, bx, by, seen, grid);
        dfs(px, py+1, bx, by, seen, grid);
        dfs(px, py-1, bx, by, seen, grid);
        dfs(px - 1, py, bx, by, seen, grid);
    }
    int minPushBox(vector<vector<char>>& grid) {
        
        m = grid.size();n = grid[0].size();
        vector<int> start, end, box;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 'S')
                    start = {i, j};
                else if(grid[i][j] == 'T')
                    end = {i, j};
                else if(grid[i][j] == 'B')
                    box = {i, j};
            }
        }
        int step = 0;
        set<pair<int, int> > seen;
        int h = hash(start[0], start[1], box[0], box[1]);
        dfs(start[0], start[1], box[0], box[1], seen, grid);
        //cout<<q.size()<<endl;
        while(q.size() > 0 ) {
            int size = q.size();
            while(size-- > 0) {
                int px, py, bx, by;
                get(q.front(), px, py, bx, by);
                q.pop();
                if(bx == end[0] && by ==end[1]) return step;
                int nx = bx, ny = by;
                bx += bx - px; by += by - py;
                if(bx < 0 || by < 0 || bx >= m || by >= n || grid[bx][by] == '#') continue;
                int h = hash(nx, ny, bx, by);
                if(v.count(h)) continue;
                seen = {};
                dfs(nx, ny, bx, by, seen, grid);
            }
            ++step;
        }
        return -1;
    }
};
```
      