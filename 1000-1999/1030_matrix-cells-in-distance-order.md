[1030.matrix-cells-in-distance-order](https://leetcode.com/problems/matrix-cells-in-distance-order/)  

We are given a matrix with `R` rows and `C` columns has cells with integer coordinates `(r, c)`, where `0 <= r < R` and `0 <= c < C`.

Additionally, we are given a cell in that matrix with coordinates `(r0, c0)`.

Return the coordinates of all cells in the matrix, sorted by their distance from `(r0, c0)` from smallest distance to largest distance.  Here, the distance between two cells `(r1, c1)` and `(r2, c2)` is the Manhattan distance, `|r1 - r2| + |c1 - c2|`.  (You may return the answer in any order that satisfies this condition.)

**Example 1:**

**Input:** R = 1, C = 2, r0 = 0, c0 = 0
**Output:** \[\[0,0\],\[0,1\]\]
**Explanation:** The distances from (r0, c0) to other cells are: \[0,1\]

**Example 2:**

**Input:** R = 2, C = 2, r0 = 0, c0 = 1
**Output:** \[\[0,1\],\[0,0\],\[1,1\],\[1,0\]\] **Explanation:** The distances from (r0, c0) to other cells are: \[0,1,1,2\]
The answer \[\[0,1\],\[1,1\],\[0,0\],\[1,0\]\] would also be accepted as correct.

**Example 3:**

**Input:** R = 2, C = 3, r0 = 1, c0 = 2
**Output:** \[\[1,2\],\[0,2\],\[1,1\],\[0,1\],\[1,0\],\[0,0\]\]
**Explanation:** The distances from (r0, c0) to other cells are: \[0,1,1,2,2,3\]
There are other answers that would also be accepted as correct, such as \[\[1,2\],\[1,1\],\[0,2\],\[1,0\],\[0,1\],\[0,0\]\].

**Note:**

1.  `1 <= R <= 100`
2.  `1 <= C <= 100`
3.  `0 <= r0 < R`
4.  `0 <= c0 < C`  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        queue<pair<int, int> > q;
        set<pair<int, int> > v;
        q.push({r0, c0});
        vector<vector<int> > ans;
        ans.push_back({r0, c0});
        v.insert({r0, c0});
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()){
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    int nx = p.first + d[i];
                    int ny = p.second + d[i+1];
                    if(nx < 0 || ny < 0 || nx >= R || ny >= C || v.count({nx, ny})) continue;
                    v.insert({nx, ny});
                    q.push({nx, ny});
                    ans.push_back({nx, ny});
                }
            }
        }
        return ans;
    }
};
```
      