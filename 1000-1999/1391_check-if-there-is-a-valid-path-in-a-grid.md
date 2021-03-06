[1391.check-if-there-is-a-valid-path-in-a-grid](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/)  

Given a _m_ x _n_ `grid`. Each cell of the `grid` represents a street. The street of `grid[i][j]` can be:

*   **1** which means a street connecting the left cell and the right cell.
*   **2** which means a street connecting the upper cell and the lower cell.
*   **3** which means a street connecting the left cell and the lower cell.
*   **4** which means a street connecting the right cell and the lower cell.
*   **5** which means a street connecting the left cell and the upper cell.
*   **6** which means a street connecting the right cell and the upper cell.

![](https://assets.leetcode.com/uploads/2020/03/05/main.png)

You will initially start at the street of the upper-left cell `(0,0)`. A valid path in the grid is a path which starts from the upper left cell `(0,0)` and ends at the bottom-right cell `(m - 1, n - 1)`. **The path should only follow the streets**.

**Notice** that you are **not allowed** to change any street.

Return _true_ if there is a valid path in the grid or _false_ otherwise.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/03/05/e1.png)

  
**Input:** grid = \[\[2,4,3\],\[6,5,2\]\]  
**Output:** true  
**Explanation:** As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/03/05/e2.png)

  
**Input:** grid = \[\[1,2,1\],\[1,2,1\]\]  
**Output:** false  
**Explanation:** As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)  

**Example 3:**

  
**Input:** grid = \[\[1,1,2\]\]  
**Output:** false  
**Explanation:** You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).  

**Example 4:**

  
**Input:** grid = \[\[1,1,1,1,1,1,3\]\]  
**Output:** true  

**Example 5:**

  
**Input:** grid = \[\[2\],\[2\],\[2\],\[2\],\[2\],\[2\],\[6\]\]  
**Output:** true  

**Constraints:**

*   `m == grid.length`
*   `n == grid[i].length`
*   `1 <= m, n <= 300`
*   `1 <= grid[i][j] <= 6`  



**Solution:**  

```cpp
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<vector<int> > > d = { 
            { {0 ,1}, {0, -1} },
            { {1, 0}, {-1, 0} },  
            { {0, -1}, {1, 0} },
            {{0, 1}, {1, 0}},
            {{-1, 0}, {0, -1}},
            {{-1, 0}, {0, 1}}
        };
        vector<vector<set<int> > > valid = { 
            { { 1, 3, 5 }, {1, 4, 6} },
            { {2,5, 6},  { 2, 3, 4}},
            {{1,4, 6}, {2, 5, 6}},
            {{1, 3, 5}, {2, 5, 6}},
            {{2, 3, 4}, {1, 4, 6}},
            {{2, 3, 4}, {1, 3, 5}}
        };
        queue<int> q;
        q.push(0);
        //cout<<"begin"<<endl;
        set<int> v;
        v.insert(0);
        while(q.size()) {
            int p = q.front();q.pop();
            int x = (p >> 16);
            int y = p & 0xffff;
            int road = grid[x][y] - 1;
            if( (x == grid.size() - 1) && (y == grid[0].size() -1)) return true;
            //cout<<x<<" "<<y<<" | ";
            for(int idx = 0; idx < 2; ++idx) {
                auto &nd = d[road][idx];
                int nx = x+ nd[0];
                int ny = y + nd[1];
                
                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
                int nhash = (nx << 16) | ny;
                if(v.count(nhash)) continue;
                int nval = grid[nx][ny];
                if(valid[road][idx].count(nval)) {
                    q.push(nhash);
                    v.insert(nhash);
                }
            }
        }
        //cout<<endl;
        return false;
    }
};
```
      