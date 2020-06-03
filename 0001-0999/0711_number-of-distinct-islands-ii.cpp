//Link: https://leetcode.com/problems/number-of-distinct-islands-ii/ 
class Solution {
public:
    set<vector<pair<int, int> > > uni;
    int numDistinctIslands2(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    vector<pair<int, int> > pairs;
                    dfs(grid, i, j, pairs);
                    normalize(pairs);
                }
            }
        }
        return uni.size();
    }
    
    void dfs(vector<vector<int> > &grid, int x, int y, vector<pair<int, int> > &pairs) {
        int m = grid.size(), n = grid[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0) return;
        pairs.push_back({x, y});
        grid[x][y] = 0;
        dfs(grid, x + 1, y, pairs);
        dfs(grid, x - 1, y , pairs);
        dfs(grid, x, y + 1, pairs);
        dfs(grid, x, y -1, pairs);
    }
    void normalize(vector<pair<int, int> > &pairs) {
        vector<vector<pair<int, int> > > shapes(8);
        for(int i = 0; i < pairs.size(); ++i) {
            auto &p = pairs[i];
            int x = p.first, y = p.second;
            shapes[0].push_back({-x, y});
            shapes[1].push_back({x, -y});
            shapes[2].push_back({-x, -y});
            shapes[3].push_back({x, y});
            swap(x, y);
            shapes[4].push_back({-x, y});
            shapes[5].push_back({x, -y});
            shapes[6].push_back({-x, -y});
            shapes[7].push_back({x, y});
        }
        for(int i = 0; i < 8; ++i) {
            sort(shapes[i].begin(), shapes[i].end());
            for(int j = shapes[i].size() - 1; j >= 0; --j) {
                shapes[i][j].first -= shapes[i][0].first;
                shapes[i][j].second -= shapes[i][0].second;
            }
        }
        sort(shapes.begin(), shapes.end());
        uni.insert(shapes[0]);
    }
};