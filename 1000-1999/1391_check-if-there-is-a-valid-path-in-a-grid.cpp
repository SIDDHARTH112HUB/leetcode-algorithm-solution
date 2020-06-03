//Link: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/ 
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<vector<int> > > d = { 
            { {0 ,1}, {0, -1} },
            { {1, 0}, {-1, 0} },  
            { {0, -1}, {1, 0} },
            {{0, 1}, {1, 0}},
            {{-1, 0}, {0, -1}},
            {{-1, 0}, {0, 1}}
        };
        vector<vector<set<int> > > valid = { 
            { { 1, 3, 5 }, {1, 4, 6} },
            { {2,5, 6},  { 2, 3, 4}},
            {{1,4, 6}, {2, 5, 6}},
            {{1, 3, 5}, {2, 5, 6}},
            {{2, 3, 4}, {1, 4, 6}},
            {{2, 3, 4}, {1, 3, 5}}
        };
        queue<int> q;
        q.push(0);
        //cout<<"begin"<<endl;
        set<int> v;
        v.insert(0);
        while(q.size()) {
            int p = q.front();q.pop();
            int x = (p >> 16);
            int y = p & 0xffff;
            int road = grid[x][y] - 1;
            if( (x == grid.size() - 1) && (y == grid[0].size() -1)) return true;
            //cout<<x<<" "<<y<<" | ";
            for(int idx = 0; idx < 2; ++idx) {
                auto &nd = d[road][idx];
                int nx = x+ nd[0];
                int ny = y + nd[1];
                
                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
                int nhash = (nx << 16) | ny;
                if(v.count(nhash)) continue;
                int nval = grid[nx][ny];
                if(valid[road][idx].count(nval)) {
                    q.push(nhash);
                    v.insert(nhash);
                }
            }
        }
        //cout<<endl;
        return false;
    }
};