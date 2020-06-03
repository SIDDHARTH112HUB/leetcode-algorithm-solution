//Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/ 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<int> q;
        if(grid[0][0] == 1) return -1;
        q.push(0);
        unordered_set<int> v;
        v.insert(0);
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0,  1,  1, 1, 0, -1, -1};
        int m = grid.size();
        int step = 1;
        int n = grid[0].size();
        if(grid[m-1][n-1] == 1) return -1;
        while(q.size() > 0){
            int size = q.size();
            while(size-- > 0) {
                int h = q.front();
                q.pop();
                int x = h >> 8;
                int y = h & 0xFF;
                if(x == m-1 && y ==n-1)
                    return step;
                for(int i = 0;i  < 8; i++) {
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 1 || v.count((nx<<8) | ny))
                        continue;
                    int nh = (nx<<8)|ny;
                    q.push(nh);
                    v.insert(nh);
                }
            }
            ++step;
        }
        return -1;
    }
};