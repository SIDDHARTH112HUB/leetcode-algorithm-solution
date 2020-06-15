[749.contain-virus](https://leetcode.com/problems/contain-virus/)  

A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as a 2-D array of cells, where `0` represents uninfected cells, and `1` represents cells contaminated with the virus. A wall (and only one wall) can be installed **between any two 4-directionally adjacent cells**, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.

Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.

**Example 1:**  

**Input:** grid = 
\[\[0,1,0,0,0,0,0,1\],
 \[0,1,0,0,0,0,0,1\],
 \[0,0,0,0,0,0,0,1\],
 \[0,0,0,0,0,0,0,0\]\]
**Output:** 10
**Explanation:**
There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

\[\[0,1,0,0,0,0,1,1\],
 \[0,1,0,0,0,0,1,1\],
 \[0,0,0,0,0,0,1,1\],
 \[0,0,0,0,0,0,0,1\]\]

On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.

**Example 2:**  

**Input:** grid = 
\[\[1,1,1\],
 \[1,0,1\],
 \[1,1,1\]\]
**Output:** 4
**Explanation:** Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.

**Example 3:**  

**Input:** grid = 
\[\[1,1,1,0,0,0,0,0,0\],
 \[1,0,1,0,1,1,1,1,1\],
 \[1,1,1,0,0,0,0,0,0\]\]
**Output:** 13
**Explanation:** The region on the left only builds two new walls.

**Note:**  

1.  The number of rows and columns of `grid` will each be in the range `[1, 50]`.
2.  Each `grid[i][j]` will be either `0` or `1`.
3.  Throughout the described process, there is always a contiguous viral region that will infect **strictly more** uncontaminated squares in the next round.  



**Solution:**  

```cpp
class Solution {
public:
    set<pair<int, int> > emptys;
    int virulCnt = 0;
    int dfs(vector<vector<int>>& grid, int x, int y, int virusVal, int emptyVal) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == virusVal || grid[x][y] == 2) return 0;
        int ans = 0;
        if(grid[x][y] == 0) {
            emptys.insert({x, y});
            grid[x][y] = emptyVal;
            return 1;
        }
        virulCnt++;
        grid[x][y] = virusVal;
        ans += dfs(grid, x + 1, y, virusVal, emptyVal);
        ans += dfs(grid, x, y + 1, virusVal, emptyVal);
        ans += dfs(grid, x - 1, y, virusVal, emptyVal);
        ans += dfs(grid, x, y - 1, virusVal, emptyVal);
        return ans;
    }
    void expand(vector<vector<int>>& grid) {
        set<pair<int, int> > v;
        
    }
    int res = 0;
    int containVirus(vector<vector<int>>& grid) {
        //cout<<"begin"<<endl;
        while(true){
            int mx = 0, px = -1, py = -1, cnt = 0, wall = 0;

            for(int i = 0; i < grid.size(); ++i) {
                for(int j = 0; j < grid[i].size(); ++j) {
                    
                    if(grid[i][j] == 1) {
                        emptys.clear();
                        cnt = dfs(grid, i, j, -1, 0);
                        if(emptys.size() > mx ||mx == 0) {
                            mx = emptys.size();
                            wall = cnt;
                            px = i, py = j;
                        }
                    }
                }
            }
            if(px >= 0) 
                dfs(grid, px, py, 2, 0);
            //cout<<"max: "<<px<<" "<<py<<" cnt:"<<wall<<endl;
            res += wall;
            for(int i = 0; i < grid.size(); ++i) {
                for(int j = 0; j < grid[i].size(); ++j) {
                    if(grid[i][j] == -1)
                        cnt += dfs(grid, i, j, 1, 1);
                }
            }
            if(cnt == 0) {
                for(int i = 0; i < grid.size(); ++i) {
                    for(int j = 0; j < grid[i].size(); ++j) {
                        if(grid[i][j] == 0)
                            return res;
                    }
                }
                return res;
            }
        }
        return res;
    }
};
```
      