//Link: https://leetcode.com/problems/bricks-falling-when-hit/ 

#define hash(x, y) (((x) << 16) | (y))
struct UF {
    unordered_map<int, int> m;
    unordered_map<int, int> g;
    int find(int x){
        if(m.count(x)) return m[x] = (m[x] == x ? x : find(m[x]));
        ++g[x];
        return m[x] = x;
    }
    
    int un(int a, int b) {
        a = find(a); b = find(b);
        if(a != b) {
            m[max(b, a)] = min(a, b);
            int rm = g[max(a, b)];
            g[min(a, b)] += rm;
            g.erase(max(a, b));
            if(((min(a, b) >> 16) == 0) && ((max(a, b) >> 16) != 0))
                return rm;
            return 0;
        }
        return 0;
    }
};

class Solution {
public:
    UF uf;
    vector<int> hitBricks(vector<vector<int>>& g, vector<vector<int>>& hits) {
        for(auto &hit : hits) {
            g[hit[0]][hit[1]] = -g[hit[0]][hit[1]];
        }
        //cout<<"-------======================--------------"<<endl;
        int d[5] = { 0, 1, 0, -1, 0};
        for(int i = 0; i < g.size(); ++i) {
            for(int j = 0; j < g[0].size(); ++j ) {
                if(g[i][j] == 1) {
                    dfs(g, i, j, hash(i, j));
                }
            }
        }
        //cout<<"---------------------"<<endl;
        vector<int> ans;
        
        for(int i = (int)hits.size()-1; i >= 0; --i){
            auto &hit = hits[i];
            int x = hit[0], y = hit[1];
            
            if(g[x][y] == 0) {
                ans.push_back(0);
                continue;
            }
            g[x][y] = 1;
            int cnt = 0;
            for(int i = 0; i < 4; ++i) {
                int nx = x + d[i];
                int ny = y + d[i+1];
                if (nx < 0 || ny < 0 || nx >= g.size() || ny >= g[0].size() || g[nx][ny] != 1) continue;
                cnt += uf.un(hash(x, y), hash(nx, ny));
            }
            ans.push_back(cnt?cnt- (x!=0):0);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(vector<vector<int>>& g, int x, int y, int h) {
        if (x < 0 || y < 0 || x >= g.size() || y >= g[0].size() || g[x][y] != 1) return;
        int cur = hash(x, y);
        if(uf.m.count(cur)) return;
        uf.un(cur, h);
        dfs(g, x + 1, y, h);
        dfs(g, x, y + 1, h);
        dfs(g, x - 1, y, h);
        dfs(g, x, y - 1, h);
    }
    
};