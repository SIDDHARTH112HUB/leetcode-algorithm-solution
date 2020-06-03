//Link: https://leetcode.com/problems/cut-off-trees-for-golf-event/ 
class Solution {
public:
    int m;
    int n;
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size(); n = forest[0].size();
        vector<vector<int> > points;
        for(int i = 0; i < forest.size(); ++i) {
            for(int j = 0; j < forest[i].size(); ++j) {
                if(forest[i][j] > 1)
                    points.push_back({forest[i][j], i, j});
            }
        }
        sort(points.begin(), points.end());
        int x = 0, y = 0, ans = 0;
        for(auto &p : points) {
            int res = f(forest, x, y, p[1], p[2]);
            if(res < 0) return -1;
            ans += res;
            x = p[1];
            y = p[2];
        }
        return ans;
    }
    
    int f(vector<vector<int>>& forest, int x, int y, int tx, int ty) {
        vector<vector<int>> vis(m, vector<int>(n));
        queue<pair<int, int> > q;
        q.push({x, y});
        vis[x][y] = 1;
        int d[5] = {0, 1, 0, -1, 0};
        int step = 0;
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto  p = q.front();
                long long px = p.first;
                long long py = p.second;
                if(px == tx && py == ty) return step;
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    long long nx = px + d[i];
                    long long ny = py + d[i+1];
                    if(nx < 0 || ny < 0 || nx >= forest.size() || ny >= forest[0].size() || forest[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                    if(nx == tx && ny == ty)
                        return step + 1;
                    
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            ++step;
        }
        return -1;
    }
};