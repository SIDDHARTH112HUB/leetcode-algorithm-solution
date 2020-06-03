//Link: https://leetcode.com/problems/the-maze/ 
class Solution {
public:
    int hash(int x, int y) {
        return  (x << 8) | y;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<int> q;
        map<int, int> v;
        int m = maze.size(), n = maze[0].size();
        int h = hash(start[0], start[1]);
        q.push(h);
        v[h] = 0;
        int ans = INT_MAX;
        int d[5] = {0, -1, 0, 1, 0};
        while(q.size()) {
            int p = q.front(); q.pop();
            int x =  p >> 8, y = p & 0xff;
            if(p == hash(destination[0], destination[1])) {
                return true;
            }
            for(int i = 0; i < 4; ++i) {
                int nx = x, ny = y;
                int step = v[p];
                while(nx >= 0 && ny >=0 && nx < m && ny < n && maze[nx][ny] == 0) {
                    nx += d[i]; ny += d[i+1];
                    ++step;
                }
                nx -= d[i]; ny -= d[i+1];
                --step;
                int nh = hash(nx, ny);
                if(v.count(nh) == 0 || step < v[nh]) {
                    v[nh] = step;
                    q.push(nh);
                }
            }
        }
        return false;
    }
};