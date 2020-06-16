[1267.count-servers-that-communicate](https://leetcode.com/problems/count-servers-that-communicate/)  

You are given a map of a server center, represented as a `m * n` integer matrix `grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.  
  
Return the number of servers that communicate with any other server.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-6.jpg)

  
**Input:** grid = \[\[1,0\],\[0,1\]\]  
**Output:** 0  
**Explanation:** No servers can communicate with others.

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/11/13/untitled-diagram-4.jpg)**

  
**Input:** grid = \[\[1,0\],\[1,1\]\]  
**Output:** 3  
**Explanation:** All three servers can communicate with at least one other server.  

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-1-3.jpg)

  
**Input:** grid = \[\[1,1,0,0\],\[0,0,1,0\],\[0,0,1,0\],\[0,0,0,1\]\]  
**Output:** 4  
**Explanation:** The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.  

**Constraints:**

*   `m == grid.length`
*   `n == grid[i].length`
*   `1 <= m <= 250`
*   `1 <= n <= 250`
*   `grid[i][j] == 0 or 1`  



**Solution:**  

```cpp
class Solution {
public:
    int m;
    int n;
    int ans = 0;
    set<pair<int, int> > v;
    int countServers(vector<vector<int>>& grid) {
        
        m = grid.size(); 
        n = grid[0].size();
        vector<int> row(m), col(n);
        for(int i =0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1){
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }for(int i =0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if((row[i] > 1 || col[j] > 1) && grid[i][j] == 1)
                    v.insert({i, j});
            }
        }
        return v.size();
    }
};
```
      