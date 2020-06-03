//Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/ 
class Solution {
public:
    int hash(int x, int y) {
       // cout<<x<<" "<<y<<endl;
        return (x <<8) | y;
    }
    void dehash(int v, int &x, int &y) {
        x = (v >> 8);
        y = (v & 0xff);
    }
    int minCost(vector<vector<int>>& grid) {
        map<int, int> seen;
        queue<int> q;
        q.push(0);
        seen[0] = 0;
        int ans = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                int x, y;
                auto h = q.front();q.pop();
                dehash(h, x, y);
                for(int i = 0; i <4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx <0  || ny <0 || nx >= grid.size() || ny >= grid[0].size()) continue;
                    int nh = hash(nx, ny);
                    int addmove = grid[x][y] != i + 1;
                    if(seen.count(nh) && seen[nh] <= seen[h] + addmove) continue;
                    seen[nh] = seen[h] + addmove;
                    q.push(nh);
                }
            }
        }
        int lh = hash(grid.size() - 1, grid[0].size() - 1);
        return seen[lh];
    }
};