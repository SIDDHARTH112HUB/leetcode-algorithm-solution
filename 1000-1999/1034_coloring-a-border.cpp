//Link: https://leetcode.com/problems/coloring-a-border/ 
class Solution {
public:
    set<pair<int, int> > v;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        //cout<<"begin"<<endl;
        dfs(grid, r0, c0, grid[r0][c0], color);
        return grid;
    }
    
    bool dfs(vector<vector<int>>& grid, int x, int y, int src, int color) {
        if(v.count({x, y})) return true;
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != src ) return false;
        v.insert({x, y});
        bool res = dfs(grid, x , y + 1, src, color);
        res = dfs(grid, x + 1, y, src, color) && res;
        res = dfs(grid, x , y - 1, src, color) && res;
        res = dfs(grid, x - 1, y, src, color) && res;
        //cout<<x<<" "<<y<<" "<<res<<endl;
        if(!res)
            grid[x][y] = color;
        return true;
    }
};