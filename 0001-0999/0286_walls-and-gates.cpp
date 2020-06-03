//Link: https://leetcode.com/problems/walls-and-gates/ 
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(); 
        if(m == 0) return;
        int n = rooms[0].size();
        if(n == 0) return;
        queue<pair<int, int> > q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int step = 1;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size--) {
                auto p = q.front(); q.pop();
                int x = p.first, y = p.second;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + d[i];
                    int ny = y + d[i + 1];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || rooms[nx][ny] != INT_MAX) continue;
                    rooms[nx][ny] = step;
                    q.push({nx, ny});
                }
            }
            ++step;
        }
    }
};