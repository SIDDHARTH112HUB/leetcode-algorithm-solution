//Link: https://leetcode.com/problems/as-far-from-land-as-possible/ 

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<pair<int, int > > v;
        int ans = 0;
        queue<pair<int, int > > q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) continue;
                q.push({i, j});
                v.insert({i, j});
            }
        }
        int d[5] = {0, 1, 0, -1, 0};
        int step = 0;
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                int x = p.first;
                int y = p.second;
                q.pop();
                for(int k = 0; k < 4; ++k) {
                    int nx = x + d[k];
                    int ny = y + d[k+1];
                    if(nx < 0 || ny < 0 || nx >=m || ny >=n || grid[nx][ny] == 1 || v.count({nx, ny}))continue;
                    v.insert({nx, ny});
                    q.push({nx, ny});
                }
            }
            ++step;
        }
        return step - 1 == 0 ? -1 : step - 1;
    }
};
