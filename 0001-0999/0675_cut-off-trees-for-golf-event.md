[675.cut-off-trees-for-golf-event](https://leetcode.com/problems/cut-off-trees-for-golf-event/)  

You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

1.  `0` represents the `obstacle` can't be reached.
2.  `1` represents the `ground` can be walked through.
3.  `The place with number bigger than 1` represents a `tree` can be walked through, and this positive number represents the tree's height.

In one step you can walk in any of the four directions `top`, `bottom`, `left` and `right` also when standing in a point which is a tree you can decide whether or not to cut off the tree.

You are asked to cut off **all** the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps **you need to walk** to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two `trees` have the same height and there is at least one tree needs to be cut off.

**Example 1:**

  
**Input:**   
\[  
 \[1,2,3\],  
 \[0,0,4\],  
 \[7,6,5\]  
\]  
**Output:** 6  

**Example 2:**

  
**Input:**   
\[  
 \[1,2,3\],  
 \[0,0,0\],  
 \[7,6,5\]  
\]  
**Output:** -1  

**Example 3:**

  
**Input:**   
\[  
 \[2,3,4\],  
 \[0,0,5\],  
 \[8,7,6\]  
\]  
**Output:** 6  
**Explanation:** You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.  

**Constraints:**

*   `1 <= forest.length <= 50`
*   `1 <= forest[i].length <= 50`
*   `0 <= forest[i][j] <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    int m;
    int n;
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size(); n = forest[0].size();
        vector<vector<int> > points;
        for(int i = 0; i < forest.size(); ++i) {
            for(int j = 0; j < forest[i].size(); ++j) {
                if(forest[i][j] > 1)
                    points.push_back({forest[i][j], i, j});
            }
        }
        sort(points.begin(), points.end());
        int x = 0, y = 0, ans = 0;
        for(auto &p : points) {
            int res = f(forest, x, y, p[1], p[2]);
            if(res < 0) return -1;
            ans += res;
            x = p[1];
            y = p[2];
        }
        return ans;
    }
    
    int f(vector<vector<int>>& forest, int x, int y, int tx, int ty) {
        vector<vector<int>> vis(m, vector<int>(n));
        queue<pair<int, int> > q;
        q.push({x, y});
        vis[x][y] = 1;
        int d[5] = {0, 1, 0, -1, 0};
        int step = 0;
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto  p = q.front();
                long long px = p.first;
                long long py = p.second;
                if(px == tx && py == ty) return step;
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    long long nx = px + d[i];
                    long long ny = py + d[i+1];
                    if(nx < 0 || ny < 0 || nx >= forest.size() || ny >= forest[0].size() || forest[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                    if(nx == tx && ny == ty)
                        return step + 1;
                    
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            ++step;
        }
        return -1;
    }
};
```
      