//Link: https://leetcode.com/problems/surrounded-regions/ 
class Solution {
public:
    int m;
    int n;
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if( m <= 2 ) return;
        n = board[0].size();
        if( n <= 2) return;
        
        
        for( int i = 0; i<m; i++){
            if( board[i][0] == 'O')
                dfs(board, i, 0);
            if( board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }
        for( int i = 0; i<n; i++){
            if( board[0][i] == 'O')
                dfs(board, 0, i);
            if( board[m-1][i] == 'O')
                dfs(board, m-1, i);
        }
        for( int i = 0; i<m ; i++){
            for( int j = 0; j<n; j++){
                if( board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if( board[i][j] == '.')
                    board[i][j] = 'O';
            }
        }
    }
    void dfs( vector<vector<char>> &board, int x, int y){
        board[x][y] = '.';
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};
        for( int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O'){
                dfs(board, nx, ny);
            }
        }
    }
};

