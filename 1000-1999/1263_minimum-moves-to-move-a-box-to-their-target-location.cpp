//Link: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ 
class Solution {
public:
    set<int> v;
    queue<int> q;
    int m;
    int n;
    int hash(int px, int py, int bx, int by) {
        return (px << 24) | (py << 16) | (bx << 8) | by;
    }
    void get(int h, int &px, int &py, int &bx, int &by) {
        px = (h >> 24) & 0xff;
        py = (h >> 16) & 0xff;
        bx = (h >> 8) & 0xff;
        by = h & 0xff;
    }
    void dfs(int px, int py, int bx, int by, set<pair<int, int> > &seen, vector<vector<char>>& grid) {
        if(px == bx && py == by ) return;
        if(px < 0 || py < 0 || px >= m || py >= n || grid[px][py] == '#') return;
        if(seen.count({px, py})) return;
        if((px == bx && abs(py - by) == 1) || (abs(px - bx) == 1 && py == by)) {
            int h = hash(px, py, bx, by);
            if(v.count(h) == 0){
                v.insert(h);
                q.push(h);
            }
        }
        seen.insert({px, py});
        dfs(px + 1, py, bx, by, seen, grid);
        dfs(px, py+1, bx, by, seen, grid);
        dfs(px, py-1, bx, by, seen, grid);
        dfs(px - 1, py, bx, by, seen, grid);
    }
    int minPushBox(vector<vector<char>>& grid) {
        
        m = grid.size();n = grid[0].size();
        vector<int> start, end, box;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 'S')
                    start = {i, j};
                else if(grid[i][j] == 'T')
                    end = {i, j};
                else if(grid[i][j] == 'B')
                    box = {i, j};
            }
        }
        int step = 0;
        set<pair<int, int> > seen;
        int h = hash(start[0], start[1], box[0], box[1]);
        dfs(start[0], start[1], box[0], box[1], seen, grid);
        //cout<<q.size()<<endl;
        while(q.size() > 0 ) {
            int size = q.size();
            while(size-- > 0) {
                int px, py, bx, by;
                get(q.front(), px, py, bx, by);
                q.pop();
                if(bx == end[0] && by ==end[1]) return step;
                int nx = bx, ny = by;
                bx += bx - px; by += by - py;
                if(bx < 0 || by < 0 || bx >= m || by >= n || grid[bx][by] == '#') continue;
                int h = hash(nx, ny, bx, by);
                if(v.count(h)) continue;
                seen = {};
                dfs(nx, ny, bx, by, seen, grid);
            }
            ++step;
        }
        return -1;
    }
};