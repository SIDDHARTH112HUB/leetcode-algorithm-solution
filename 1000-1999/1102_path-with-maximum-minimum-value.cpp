//Link: https://leetcode.com/problems/path-with-maximum-minimum-value/ 
class Solution {
public:
    int maximumMinimumPath(vector<vector<int> >& A) {
        
        int m = A.size();
        int n = A[0].size();
        int mp[m][n];
        memset(mp, 0, sizeof(mp));
        queue<pair<int, int> > q;
        q.push({0, 0});
        mp[0][0] = A[0][0];
        int d[5] = {0, -1, 0, 1, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                q.pop();
                int cur = mp[p.first][p.second];
                for(int i = 0;i < 4; ++i) {
                    int nx = p.first + d[i];
                    int ny = p.second + d[i+1];
                    if(nx < 0|| ny < 0 || nx >=m || ny >= n) continue;
                    if(mp[nx][ny] < min(cur, A[nx][ny])){
                        mp[nx][ny] = min(cur, A[nx][ny]);
                        q.push({nx, ny});
                    }
                }
            }
        }
        return mp[m-1][n-1];
    }
};