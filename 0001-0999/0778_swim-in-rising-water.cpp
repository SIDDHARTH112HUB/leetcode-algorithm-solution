//Link: https://leetcode.com/problems/swim-in-rising-water/ 
class Solution {
public:
    int n;
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int mx = 0;
        if( n == 0) return 0;
        for(auto &vec : grid) {
            for(auto num : vec)
                mx = max(mx, num);
        }
        int l = 0, r = mx;
        while(l < r) {
            int mid = (l+r) / 2;
            set<pair<int, int> > m;
            if(dfs(grid, 0, 0, mid, m))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
    
    bool dfs(vector<vector<int>>& grid, int x, int y, int h, set<pair<int, int> > &m) {
        if(x < 0 || y < 0 || x >= n || y >= n || m.count({x, y}) || grid[x][y] > h) return false;
        if( x == n - 1 && y == n - 1) return true;
        m.insert({x, y});
        return dfs(grid, x + 1, y, h, m) ||
            dfs(grid, x, y + 1, h, m) ||
            dfs(grid, x - 1, y, h, m) ||
            dfs(grid, x, y - 1, h, m);
    }
};