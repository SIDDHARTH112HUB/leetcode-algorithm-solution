//Link: https://leetcode.com/problems/queens-that-can-attack-the-king/ 
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int> > grid(8, vector<int>(8));
        for(auto &queen: queens) {
            grid[queen[0]][queen[1]] = 1;
        }
        int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
        int dy[8] = {1, -1,1, -1, 0,1, -1, 0};
        vector<vector<int> > ans;
        for(auto &queen: queens) {
            int x = queen[0];
            int y = queen[1];
            bool dir[8] = {0};
            memset(dir, 0, sizeof(dir));
            int block = 0;
            bool hit = false;
            int nxs[8] = {x, x, x, x, x ,x,x,x};
            int nys[8] = {y,y,y,y,y,y,y,y};
            while(hit == false && block <8){
                for(int i = 0; i < 8; ++i) {
                    if(dir[i]) continue;
                    nxs[i] += dx[i];
                    nys[i] += dy[i];
                    int nx = nxs[i];
                    int ny = nys[i];
                    if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || grid[nx][ny] != 0) {
                        dir[i] = true;
                        ++block;
                        continue;
                    }
                    if(nx == king[0] && ny == king[1]) {
                        hit = true;
                        break;
                    }
                }
            }
            if(hit == true)
                ans.push_back(queen);
        }
        return ans;
    }
};