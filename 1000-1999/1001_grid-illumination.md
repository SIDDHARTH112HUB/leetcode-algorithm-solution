[1001.grid-illumination](https://leetcode.com/problems/grid-illumination/)  

On a `N x N` grid of cells, each cell `(x, y)` with `0 <= x < N` and `0 <= y < N` has a lamp.

Initially, some number of lamps are on.  `lamps[i]` tells us the location of the `i`\-th lamp that is on.  Each lamp that is on illuminates every square on its x-axis, y-axis, and both diagonals (similar to a Queen in chess).

For the i-th query `queries[i] = (x, y)`, the answer to the query is 1 if the cell (x, y) is illuminated, else 0.

After each query `(x, y)` \[in the order given by `queries`\], we turn off any lamps that are at cell `(x, y)` or are adjacent 8-directionally (ie., share a corner or edge with cell `(x, y)`.)

Return an array of answers.  Each value `answer[i]` should be equal to the answer of the `i`\-th query `queries[i]`.

**Example 1:**

**Input:** N = 5, lamps = \[\[0,0\],\[4,4\]\], queries = \[\[1,1\],\[1,0\]\]
**Output:** \[1,0\]
**Explanation:** 
Before performing the first query we have both lamps \[0,0\] and \[4,4\] on.
The grid representing which cells are lit looks like this, where \[0,0\] is the top left corner, and \[4,4\] is the bottom right corner:
1 1 1 1 1
1 1 0 0 1
1 0 1 0 1
1 0 0 1 1
1 1 1 1 1
Then the query at \[1, 1\] returns 1 because the cell is lit.  After this query, the lamp at \[0, 0\] turns off, and the grid now looks like this:
1 0 0 0 1
0 1 0 0 1
0 0 1 0 1
0 0 0 1 1
1 1 1 1 1
Before performing the second query we have only the lamp \[4,4\] on.  Now the query at \[1,0\] returns 0, because the cell is no longer lit.

**Note:**

1.  `1 <= N <= 10^9`
2.  `0 <= lamps.length <= 20000`
3.  `0 <= queries.length <= 20000`
4.  `lamps[i].length == queries[i].length == 2`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, int> row, col, dia, anti_dia;
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set< pair<int, int> > l; //location
        for( auto &lamp: lamps){
            int x = lamp[0], y = lamp[1];
            l.insert({x, y});
            
            setLamp(x, y, 1);
        }
        int dx[9] = {0,0,0,1,-1, 1,1,-1,-1};
        int dy[9] = {0,1,-1,0,0, 1,-1,1,-1};
        vector<int> ans;
        for( auto &q : queries){
            int x = q[0], y = q[1];
            if( row[x] > 0 || col[y] > 0 || dia[x+y]>0 || anti_dia[x-y]>0 )
                ans.push_back(1);
            else
                ans.push_back(0);
            
            //remove lamp
            for( int i = 0; i<9; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if( l.count({nx, ny}) ){
                    setLamp(nx, ny, -1);
                }
            }
        }
        return ans;
    }
    
    void setLamp(int x, int y, int count){
        row[x] += count;
        col[y] += count;
        dia[x + y] += count;
        anti_dia[x - y] += count;
    }
};
```
      