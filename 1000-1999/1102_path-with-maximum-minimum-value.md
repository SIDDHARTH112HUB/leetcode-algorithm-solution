[1102.path-with-maximum-minimum-value](https://leetcode.com/problems/path-with-maximum-minimum-value/)  

Given a matrix of integers `A` with R rows and C columns, find the **maximum** score of a path starting at `[0,0]` and ending at `[R-1,C-1]`.

The _score_ of a path is the **minimum** value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A _path_ moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/04/23/1313_ex1.JPG)**

**Input:** \[\[5,4,5\],\[1,2,6\],\[7,4,6\]\]
**Output:** 4
**Explanation:** 
The path with the maximum score is highlighted in yellow. 

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/04/23/1313_ex2.JPG)**

**Input:** \[\[2,2,1,2,2,2\],\[1,2,2,2,1,2\]\]
**Output: 2**

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/04/23/1313_ex3.JPG)**

**Input:** \[\[3,4,6,3,4\],\[0,2,1,1,7\],\[8,8,3,2,7\],\[3,2,4,9,8\],\[4,1,2,0,0\],\[4,6,5,4,3\]\]
**Output: 3**

**Note:**

1.  `1 <= R, C <= 100`
2.  `0 <= A[i][j] <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    int maximumMinimumPath(vector<vector<int> >& A) {
        
        int m = A.size();
        int n = A[0].size();
        int mp[m][n];
        memset(mp, 0, sizeof(mp));
        queue<pair<int, int> > q;
        q.push({0, 0});
        mp[0][0] = A[0][0];
        int d[5] = {0, -1, 0, 1, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                q.pop();
                int cur = mp[p.first][p.second];
                for(int i = 0;i < 4; ++i) {
                    int nx = p.first + d[i];
                    int ny = p.second + d[i+1];
                    if(nx < 0|| ny < 0 || nx >=m || ny >= n) continue;
                    if(mp[nx][ny] < min(cur, A[nx][ny])){
                        mp[nx][ny] = min(cur, A[nx][ny]);
                        q.push({nx, ny});
                    }
                }
            }
        }
        return mp[m-1][n-1];
    }
};
```
      