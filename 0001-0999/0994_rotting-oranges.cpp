//Link: https://leetcode.com/problems/rotting-oranges/ 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int> > q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for( int i= 0; i< m; i++){
            for( int j = 0; j < n; j++ ){
                if( grid[i][j] == 2 )
                    q.push({i, j });
                if( grid[i][j] == 1 )
                    ++fresh;
            }
        }
        int ans = 0 ;
        if( fresh == 0 )
            return 0;
        while( q.size() > 0 ){
            int size = q.size();
            int r = 0;
            while( size-- > 0 ){
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                int d[5] = {0, 1, 0, -1, 0};
                for( int i = 0; i < 4; i++){
                    int nx = x + d[i];
                    int ny = y + d[i+1];
                    if( nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1 )
                        continue;
                    ++r;
                    --fresh;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            ans += r>0?1:0;
        }
        return fresh>0?-1:ans;
    }
};