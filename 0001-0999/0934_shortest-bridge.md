[934.shortest-bridge](https://leetcode.com/problems/shortest-bridge/)  

In a given 2D binary array `A`, there are two islands.  (An island is a 4-directionally connected group of `1`s not connected to any other 1s.)

Now, we may change `0`s to `1`s so as to connect the two islands together to form 1 island.

Return the smallest number of `0`s that must be flipped.  (It is guaranteed that the answer is at least 1.)

**Example 1:**

**Input:** A = \[\[0,1\],\[1,0\]\]  
**Output:** 1  

**Example 2:**

**Input:** A = \[\[0,1,0\],\[0,0,0\],\[0,0,1\]\]  
**Output:** 2  

**Example 3:**

**Input:** A = \[\[1,1,1,1,1\],\[1,0,0,0,1\],\[1,0,1,0,1\],\[1,0,0,0,1\],\[1,1,1,1,1\]\]  
**Output:** 1  

**Constraints:**

*   `2 <= A.length == A[0].length <= 100`
*   `A[i][j] == 0` or `A[i][j] == 1`  



**Solution:**  

```cpp
class Solution {
public:
    
    int shortestBridge(vector<vector<int>>& A) {
        vector< vector<int> > a, b;
        for( int i = 0; i < A.size(); i++){
            for( int j = 0; j < A[i].size(); j++){
                auto &group = a.size() == 0?a:b;
                if( A[i][j] == 1){
                    dfs(A, i, j, group);
                }
            }
        }
        int ans = INT_MAX;
        for( auto &pointA : a){
            for( auto &pointB : b){
                ans = min(ans, abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1])-1 );
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& A, int x, int y, vector<vector<int> > &group){
        int d[5] = {0,1,0,-1,0};
        int m = A.size();
        int n = A[0].size();
        A[x][y] = 0;
        group.push_back({x, y});
        for( int i = 0; i < 4; i++){
            int nx = x + d[i];
            int ny = y + d[i+1];
            if( nx >= 0 && ny >= 0 && nx < m && ny < n && A[nx][ny] == 1){
                dfs(A, nx, ny, group);
            }
        }
    }
};
```
      