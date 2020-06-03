//Link: https://leetcode.com/problems/contain-virus/ 
class Solution {
public:
    set<pair<int, int> > emptys;
    int virulCnt = 0;
    int dfs(vector<vector<int>>& grid, int x, int y, int virusVal, int emptyVal) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == virusVal || grid[x][y] == 2) return 0;
        int ans = 0;
        if(grid[x][y] == 0) {
            emptys.insert({x, y});
            grid[x][y] = emptyVal;
            return 1;
        }
        virulCnt++;
        grid[x][y] = virusVal;
        ans += dfs(grid, x + 1, y, virusVal, emptyVal);
        ans += dfs(grid, x, y + 1, virusVal, emptyVal);
        ans += dfs(grid, x - 1, y, virusVal, emptyVal);
        ans += dfs(grid, x, y - 1, virusVal, emptyVal);
        return ans;
    }
    void expand(vector<vector<int>>& grid) {
        set<pair<int, int> > v;
        
    }
    int res = 0;
    int containVirus(vector<vector<int>>& grid) {
        //cout<<"begin"<<endl;
        while(true){
            int mx = 0, px = -1, py = -1, cnt = 0, wall = 0;

            for(int i = 0; i < grid.size(); ++i) {
                for(int j = 0; j < grid[i].size(); ++j) {
                    
                    if(grid[i][j] == 1) {
                        emptys.clear();
                        cnt = dfs(grid, i, j, -1, 0);
                        if(emptys.size() > mx ||mx == 0) {
                            mx = emptys.size();
                            wall = cnt;
                            px = i, py = j;
                        }
                    }
                }
            }
            if(px >= 0) 
                dfs(grid, px, py, 2, 0);
            //cout<<"max: "<<px<<" "<<py<<" cnt:"<<wall<<endl;
            res += wall;
            for(int i = 0; i < grid.size(); ++i) {
                for(int j = 0; j < grid[i].size(); ++j) {
                    if(grid[i][j] == -1)
                        cnt += dfs(grid, i, j, 1, 1);
                }
            }
            if(cnt == 0) {
                for(int i = 0; i < grid.size(); ++i) {
                    for(int j = 0; j < grid[i].size(); ++j) {
                        if(grid[i][j] == 0)
                            return res;
                    }
                }
                return res;
            }
        }
        return res;
    }
};