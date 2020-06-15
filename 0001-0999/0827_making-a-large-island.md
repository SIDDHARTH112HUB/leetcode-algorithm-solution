[827.making-a-large-island](https://leetcode.com/problems/making-a-large-island/)  

In a 2D grid of `0`s and `1`s, we change at most one `0` to a `1`.

After, what is the size of the largest island? (An island is a 4-directionally connected group of `1`s).

**Example 1:**

**Input:** \[\[1, 0\], \[0, 1\]\]
**Output:** 3
**Explanation:** Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

**Example 2:**

**Input:** \[\[1, 1\], \[1, 0\]\]
**Output:** 4
**Explanation:** Change the 0 to 1 and make the island bigger, only one island with area = 4.

**Example 3:**

**Input:** \[\[1, 1\], \[1, 1\]\]
**Output:** 4
**Explanation:** Can't change any 0 to 1, only one island with area = 4.

Notes:

*   `1 <= grid.length = grid[0].length <= 50`.
*   `0 <= grid[i][j] <= 1`.  



**Solution:**  

```cpp
struct UF {
    unordered_map<int, int> m;
    unordered_map<int, int> group;
    int find(int x) {
        if(m.count(x)) return m[x] == x ? x : m[x] = find(m[x]);
        group[x] = 1;
        return m[x] = x;
    }
    
    bool combine(int a, int b) {
        a = find(a);
        b = find(b);
        if( a != b) {
            group[a] += group[b];
            m[b] = a;
            group.erase(b);
        }
        return a != b;
    }
};

#define hash(x, y) (((x) * 100) + (y))
#define X(x) ((x)/100)
#define Y(y) ((y)%100)
class Solution {
public:
    UF uf;
    int largestIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                int p = hash(i, j);
                dfs(grid, p, i, j);
            }
        }
        int d[5] = {0, 1, 0, -1, 0};
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) continue;
                unordered_map<int, int> m;
                for(int k = 0; k < 4; ++k) {
                    int x = i+d[k], y = j + d[k+1];
                    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) continue;
                    int h = hash(x, y);
                    int p = uf.m[h];
                    m[p] = uf.group[p];
                }
                int sum = 1;
                for(auto &it : m){
                    sum += it.second;
                }
                ans = max(ans, sum);
            }
        }
        return ans == 0 ? grid.size() * grid[0].size() : ans;
    }
    void dfs(vector<vector<int>>& grid, int p, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) return;
        int h = hash(x, y);
        if(uf.m.count(h)) return;
        uf.combine(p, h);
        dfs(grid, p, x+1, y);
        dfs(grid, p, x, y+1);
        dfs(grid, p, x-1, y);
        dfs(grid, p, x, y-1);
    }
};
```
      