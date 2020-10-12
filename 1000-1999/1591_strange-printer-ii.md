[1591.strange-printer-ii](https://leetcode.com/problems/strange-printer-ii/)  

There is a strange printer with the following two special requirements:

*   On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
*   Once the printer has used a color for the above operation, **the same color cannot be used again**.

You are given a `m x n` matrix `targetGrid`, where `targetGrid[row][col]` is the color in the position `(row, col)` of the grid.

Return `true` _if it is possible to print the matrix_ `targetGrid`_,_ _otherwise, return_ `false`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/15/sample_1_1929.png)

  
**Input:** targetGrid = \[\[1,1,1,1\],\[1,2,2,1\],\[1,2,2,1\],\[1,1,1,1\]\]  
**Output:** true  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/08/15/sample_2_1929.png)

  
**Input:** targetGrid = \[\[1,1,1,1\],\[1,1,3,3\],\[1,1,3,4\],\[5,5,1,4\]\]  
**Output:** true  

**Example 3:**

  
**Input:** targetGrid = \[\[1,2,1\],\[2,1,2\],\[1,2,1\]\]  
**Output:** false  
**Explanation:** It is impossible to form targetGrid because it is not allowed to print the same color in different turns.

**Example 4:**

  
**Input:** targetGrid = \[\[1,1,1\],\[3,1,3\]\]  
**Output:** false  

**Constraints:**

*   `m == targetGrid.length`
*   `n == targetGrid[i].length`
*   `1 <= m, n <= 60`
*   `1 <= targetGrid[row][col] <= 60`  



**Solution:**  

```cpp
class Solution {
public:
    int m = 0;
    int n = 0;
    map<int, set<int> > g;
    vector<int> vis3;
    void h(vector<vector<int>>& tg, int val, pair<int, int> &tl, pair<int, int> &br) {
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(tg[i][j] != val) {
                    continue;
                }
                tl.first = min(tl.first, i);
                tl.second = min(tl.second, j);
                br.first = max(br.first, i);
                br.second = max(br.second, j);
            }
        }
        for(int i = tl.first; i <= br.first; ++i) {
            for(int j = tl.second; j <= br.second; ++j) {
                if(tg[i][j] && tg[i][j] != val) {
                    g[val].insert(tg[i][j]);
                }
            }
        }
    }
    
    bool vis1[61];
    bool vis2[61];
    bool dfs(int n) {
        if(vis2[n]) return false;
        if(vis1[n]) return true;
        vis1[n] = true;
        vis2[n] = true;
        for(auto next : g[n]) {
            if(!dfs(next))
                return false;
        }
        vis2[n] = false;
        return true;
    }
    bool isPrintable(vector<vector<int>>& tg) {
        // cout<<"begin"<<endl;
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        vis3.resize(61);
        m = tg.size();
        n = tg[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(vis3[tg[i][j]]) continue;
                vis3[tg[i][j]] = 1;
                pair<int, int> tl = {i, j}, br = {i, j};
                h(tg, tg[i][j], tl, br);
            }
        }
        for(int i = 1; i <= 60; ++i) {
            if(g.count(i) == 0) continue;
            if(vis1[i] == false && !dfs(i)) return false;
        }
        return true;
    }
};
```
      