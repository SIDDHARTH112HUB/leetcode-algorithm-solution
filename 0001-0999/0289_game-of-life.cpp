//Link: https://leetcode.com/problems/game-of-life/ 
class Solution {
public:
    int newState(vector<vector<int>>& board, int x, int y){
        int m = board.size();
        int n = board[0].size();
        int state = (board[x][y] & 1) ;
        int d[9] = { 1,0,-1,0,1,1,-1,-1,1};
        int live = 0, die = 0;
        for( int i = 0; i<= 7; i++){
            int nx = x - d[i];
            int ny = y - d[i+1];
            if( nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            live += (board[nx][ny] & 1);
            die += ( (board[nx][ny] & 1) == 0? 1:0);
        }
        if( state == 0 && live == 3 )
            return 1;
        if( state == 1 ){
            if( live <  2)  return 0;
            if( live == 2 || live == 3 ) return state;
            if( live > 3 ) return 0;
        }
        return state;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for( int i = 0; i<m ; i++){ 
            for( int j = 0; j<n; j++){
                board[i][j]  |= (newState(board, i, j) << 1);
            }
        }
        for( int i = 0; i<m ; i++){ 
            for( int j = 0; j<n; j++){
                board[i][j] = board[i][j]>>1;
            }
        }
    }
};