//Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/ 
class Solution {
public:
    int hash(int k, int x, int y) {
        return (k << 16) | (x << 8) | y;
    }
    int shortestPath(vector<vector<int>>& grid, int K) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int> > q;
        map<int, map<int, int > > v;
        q.push({0, 0, 0});
        v[0][0] = 0;
        int step = 0;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto &arr = q.front();
                int k = arr[0], x = arr[1], y = arr[2];
                if(x == m-1 && y == n -1)
                    return step;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + d[i];
                    int ny = y + d[i + 1];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    if(grid[nx][ny] == 1 && k == K) continue;
                    int nk = k+grid[nx][ny];
                    if(v[nx].count(ny)) {
                        if(v[nx][ny] <= nk)
                            continue;
                    }
                    q.push({nk, nx, ny});
                    v[nx][ny] = nk;
                }
                q.pop();
            }
            ++step;
        }
        return -1;
    }
};