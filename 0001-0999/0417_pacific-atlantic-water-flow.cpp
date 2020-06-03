//Link: https://leetcode.com/problems/pacific-atlantic-water-flow/ 
class Solution {
public:
    vector<pair<int, int> > ans;
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if( n == 0 ) return ans;
        int m = matrix[0].size();
        if( m == 0 ) return ans;
        vector<vector<int>> p_matrix(n, vector<int>(m, 0));
        vector<vector<int>> a_matrix(n, vector<int>(m, 0));;
        for( int i = 0; i<n; i++){
            p_matrix[i][0] = a_matrix[i][m-1] = 1;
        }
        for( int i = 0; i<m; i++){
            p_matrix[0][i] = a_matrix[n-1][i] = 1;
        }
        bfs(p_matrix,matrix, n, m);
        bfs(a_matrix, matrix, n, m);
        for( int i = 0; i<n; i++){
            for( int j = 0; j<m; j++){
                if( p_matrix[i][j] == a_matrix[i][j] && p_matrix[i][j]  == 1)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
    
    void bfs(vector<vector<int>>& target, vector< vector<int> >& matrix, int n, int m){
        queue<pair<int, int>> q;
        for( int i = 0; i<n ; i++){
            for( int j = 0; j<m; j++ ){
                if( target[i][j] == 1 ){
                    q.push({i, j});
                }
            }
        }
        for(; q.empty() == false; q.pop()){
            auto& cood = q.front();
            int x = cood.first;
            int y = cood.second;
            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};
            for( int i = 0; i<=3; i++){
                int tx = x+dx[i];
                int ty = y+dy[i];
                if( tx >=0 && ty >= 0 && tx<n && ty<m && matrix[x][y] <= matrix[tx][ty] && target[tx][ty] == 0 ){
                    target[tx][ty] = 1;
                    q.push({tx, ty});
                }
            }
        }
    }    
};



