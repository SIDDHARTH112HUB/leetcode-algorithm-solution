//Link: https://leetcode.com/problems/unique-paths-iii/ 
class Solution {
public:
    unordered_set< int > v;
    pair<int, int> end;
    pair<int, int> start;
    int m;
    int n;
    int total = 0;
    int ans = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for( int i = 0; i< grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if( grid[i][j] == 1 )
                    start = {i, j};
                else if( grid[i][j] == 2 )
                    end = {i, j};
                if( grid[i][j] != -1 )
                    total++;
            }
        }
        dfs(grid, start.first, start.second, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& grid, int x, int y, int num ){
        int hash = (x<<10)+y;
        if( x < 0 || y < 0 || x >=m || y >= n || grid[x][y] == -1 || v.count(hash) ) return;
        num++;
        if( grid[x][y] == 2 ){
            if( num == total )
                ans++;
            return;
        }
        v.insert(hash);
        dfs(grid, x+1, y, num);
        dfs(grid, x, y+1, num);
        dfs(grid, x-1, y, num);
        dfs(grid, x, y-1, num);
        v.erase(hash);
    }
};