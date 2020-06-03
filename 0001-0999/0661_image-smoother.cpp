//Link: https://leetcode.com/problems/image-smoother/ 
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size();
        if( n == 0 ) return {};
        int m = M[0].size();
        if( m == 0 ) return {};
        vector<vector<int> > ans(n, vector<int>(m));
        int dx[8] = {0,0,1,-1,1,1,-1,-1};
        int dy[8] = {1,-1,0,0,1,-1,1,-1};
        for( int i = 0; i< n; i++){
            for( int j = 0; j < m; j++){
                int sum = M[i][j];
                int cnt = 1;
                for( int k = 0; k<8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if( nx < 0 || ny < 0 || nx >=n || ny >= m) continue;
                    sum += M[nx][ny];
                    ++cnt;
                }
                ans[i][j] = sum/cnt;
            }
        }
        return ans;
    }
};