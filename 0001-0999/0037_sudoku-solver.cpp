//Link: https://leetcode.com/problems/sudoku-solver/ 
class Solution {
public:
    bool check(vector<vector<char>>& board, char num, int row, int col ){
        for( int i = 0; i<9;i++ ){
            if( board[row][i] == num )
                return false;
            if( board[i][col] == num)
                return false;
            if( board[row/3*3 + i/3 ][col/3*3 +i%3] == num )
                return false;
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board, int i=0, int j = 0) {
        if(j == 9 ) return solveSudoku(board, i+1, 0);
        if(i == 9 ) return true;
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);
        bool flag = false;
        for( char n = '1'; n<='9'; n++){
            if( check( board, n, i, j) ){
                flag = true;
                board[i][j] = n;
                bool res = solveSudoku(board, i, j+1);
                if( res )
                    return res;
                else
                    board[i][j] = '.';
            }
        }
        return false;
    }
};