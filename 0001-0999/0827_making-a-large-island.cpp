//Link: https://leetcode.com/problems/making-a-large-island/ 
struct UF {
    unordered_map<int, int> m;
    unordered_map<int, int> group;
    int find(int x) {
        if(m.count(x)) return m[x] == x ? x : m[x] = find(m[x]);
        group[x] = 1;
        return m[x] = x;
    }
    
    bool combine(int a, int b) {
        a = find(a);
        b = find(b);
        if( a != b) {
            group[a] += group[b];
            m[b] = a;
            group.erase(b);
        }
        return a != b;
    }
};

#define hash(x, y) (((x) * 100) + (y))
#define X(x) ((x)/100)
#define Y(y) ((y)%100)
class Solution {
public:
    UF uf;
    int largestIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                int p = hash(i, j);
                dfs(grid, p, i, j);
            }
        }
        int d[5] = {0, 1, 0, -1, 0};
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) continue;
                unordered_map<int, int> m;
                for(int k = 0; k < 4; ++k) {
                    int x = i+d[k], y = j + d[k+1];
                    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) continue;
                    int h = hash(x, y);
                    int p = uf.m[h];
                    m[p] = uf.group[p];
                }
                int sum = 1;
                for(auto &it : m){
                    sum += it.second;
                }
                ans = max(ans, sum);
            }
        }
        return ans == 0 ? grid.size() * grid[0].size() : ans;
    }
    void dfs(vector<vector<int>>& grid, int p, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) return;
        int h = hash(x, y);
        if(uf.m.count(h)) return;
        uf.combine(p, h);
        dfs(grid, p, x+1, y);
        dfs(grid, p, x, y+1);
        dfs(grid, p, x-1, y);
        dfs(grid, p, x, y-1);
    }
};