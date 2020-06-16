[317.shortest-distance-from-all-buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/)  

You want to build a house on an _empty_ land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values **0**, **1** or **2**, where:

*   Each **0** marks an empty land which you can pass by freely.
*   Each **1** marks a building which you cannot pass through.
*   Each **2** marks an obstacle which you cannot pass through.

**Example:**

  
**Input:** \[\[1,0,2,0,1\],\[0,0,0,0,0\],\[0,0,1,0,0\]\]
  

  
1 - 0 - 2 - 0 - 1
  
|   |   |   |   |
  
0 - 0 - 0 - 0 - 0
  
|   |   |   |   |
  
0 - 0 - 1 - 0 - 0
  

  
**Output:** 7 
  

  
**Explanation:** Given three buildings at `(0,0)`, `(0,4)`, `(2,2)`, and an obstacle at `(0,2),
  
             t`he point `(1,2)` is an ideal empty land to build a house, as the total 
  
             travel distance of 3+3+1=7 is minimal. So return 7.

**Note:**  
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.  



**Solution:**  

```cpp
/*template<typename T>
int bfs(queue<T> &q, set<T> &v) {
    while(q.size()) {
        int size = q.size();
        auto p = q.front(); q.pop();
        
        for(int i = 0; i < 4; ++i) {

        }
    }
}*/
typedef long long ll;
class Solution {
public:
    long long hash(ll x, ll y, ll ox, ll oy) {
        return (x << 48) | (y <<32) | (ox << 16) | oy;
    }
    
    void dehash(ll h, ll &x, ll &y, ll &ox, ll &oy) {
        x = (h >> 48);
        y = (h >> 32) & 0xffff;
        ox = (h >> 16) & 0xffff;
        oy = h & 0xffff;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int, int> > > dist(m, vector<pair<int, int> >(n));
        queue<ll> q;
        set<ll> v;
        int bc = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    ++bc;
                    q.push(hash(i, j, i, j));
                    v.insert(hash(i, j, i, j));
                }
            }
        }
        int d[5] = { 0, 1, 0, -1, 0 };
        int step = 1;
        while(q.size()) {
            int size = q.size();
            while(size--) {
                auto p = q.front(); q.pop();
                ll x, y, orix, oriy;
                dehash(p, x, y, orix, oriy);
                for(int i = 0; i < 4; ++i) {
                    int nx = x + d[i], ny = y + d[i + 1];
                    if(nx < 0 || ny < 0 || nx >= m|| ny >= n || v.count(hash(nx, ny, orix, oriy)) || grid[nx][ny] != 0) continue;
                    ++dist[nx][ny].first;
                    dist[nx][ny].second += step;
                    q.push(hash(nx, ny, orix, oriy));
                    v.insert(hash(nx, ny, orix, oriy));
                }
            }
            ++step;
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                auto p = dist[i][j];
                int cnt = p.first, step = p.second;
                if(cnt == bc && step < ans) {
                    ans = step;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```
      