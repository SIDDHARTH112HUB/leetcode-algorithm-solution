[803.bricks-falling-when-hit](https://leetcode.com/problems/bricks-falling-when-hit/)  

We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.

We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.

Return an array representing the number of bricks that will drop after each erasure in sequence.

**Example 1:**
**Input:** 
grid = \[\[1,0,0,0\],\[1,1,1,0\]\]
hits = \[\[1,0\]\]
**Output:** \[2\]
**Explanation:** 
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.

**Example 2:**
**Input:** 
grid = \[\[1,0,0,0\],\[1,1,0,0\]\]
hits = \[\[1,1\],\[1,0\]\]
**Output:** \[0,0\]
**Explanation:** 
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.

**Note:**

*   The number of rows and columns in the grid will be in the range \[1, 200\].
*   The number of erasures will not exceed the area of the grid.
*   It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
*   An erasure may refer to a location with no brick - if it does, no bricks drop.  



**Solution:**  

```cpp

#define hash(x, y) (((x) << 16) | (y))
struct UF {
    unordered_map<int, int> m;
    unordered_map<int, int> g;
    int find(int x){
        if(m.count(x)) return m[x] = (m[x] == x ? x : find(m[x]));
        ++g[x];
        return m[x] = x;
    }
    
    int un(int a, int b) {
        a = find(a); b = find(b);
        if(a != b) {
            m[max(b, a)] = min(a, b);
            int rm = g[max(a, b)];
            g[min(a, b)] += rm;
            g.erase(max(a, b));
            if(((min(a, b) >> 16) == 0) && ((max(a, b) >> 16) != 0))
                return rm;
            return 0;
        }
        return 0;
    }
};

class Solution {
public:
    UF uf;
    vector<int> hitBricks(vector<vector<int>>& g, vector<vector<int>>& hits) {
        for(auto &hit : hits) {
            g[hit[0]][hit[1]] = -g[hit[0]][hit[1]];
        }
        //cout<<"-------======================--------------"<<endl;
        int d[5] = { 0, 1, 0, -1, 0};
        for(int i = 0; i < g.size(); ++i) {
            for(int j = 0; j < g[0].size(); ++j ) {
                if(g[i][j] == 1) {
                    dfs(g, i, j, hash(i, j));
                }
            }
        }
        //cout<<"---------------------"<<endl;
        vector<int> ans;
        
        for(int i = (int)hits.size()-1; i >= 0; --i){
            auto &hit = hits[i];
            int x = hit[0], y = hit[1];
            
            if(g[x][y] == 0) {
                ans.push_back(0);
                continue;
            }
            g[x][y] = 1;
            int cnt = 0;
            for(int i = 0; i < 4; ++i) {
                int nx = x + d[i];
                int ny = y + d[i+1];
                if (nx < 0 || ny < 0 || nx >= g.size() || ny >= g[0].size() || g[nx][ny] != 1) continue;
                cnt += uf.un(hash(x, y), hash(nx, ny));
            }
            ans.push_back(cnt?cnt- (x!=0):0);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(vector<vector<int>>& g, int x, int y, int h) {
        if (x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] != 1) return;
        int cur = hash(x, y);
        if(uf.m.count(cur)) return;
        uf.un(cur, h);
        dfs(g, x + 1, y, h);
        dfs(g, x, y + 1, h);
        dfs(g, x - 1, y, h);
        dfs(g, x, y - 1, h);
    }
    
};
```
      