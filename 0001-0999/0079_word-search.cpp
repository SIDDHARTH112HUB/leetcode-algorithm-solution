//Link: https://leetcode.com/problems/word-search/ 
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if( word.size() == 0 ) return true;
        for( int i = 0; i< board.size(); i++){
            for( int j = 0; j<board[0].size(); j++){
                //if( board[i][j] == word[0] ){
                //    board[i][j] = '.'
                    if( dfs(board, i, j, word, 0) )
                        return true;
                //}
            }
        }
        return false;
    }
    bool dfs( vector<vector<char> > &board, int x, int y, string &word, int idx){
        if( word[idx] != board[x][y] ) return false;
        if( idx >= word.size()-1 ) return true;
        int d[5] = {-1, 0, 1, 0,-1};
        char c = board[x][y];
        board[x][y] = '.';
        for(int i = 0; i<4; i++ ){
            int nx = x + d[i];
            int ny = y + d[i+1];
            if( nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() 
               && word[idx+1] == board[nx][ny] && board[nx][ny] != '.'){
                if(dfs(board, nx, ny, word, idx+1 ))
                    return true;
            }          
        }
        board[x][y] = c;
        return false;
    }
};