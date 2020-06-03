//Link: https://leetcode.com/problems/valid-tic-tac-toe-state/ 
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int X = 0, O=0;
        for( auto &b : board){
            for( char c : b){
                if( c == 'X')
                    X++;
                else if( c== 'O')
                    O++;
            }
        }
        if( O > X)
            return false;
        if( abs(O-X)>1 )
            return false;
        bool O_win = false;
        bool X_win = false;
        for( int i =0; i<3; i++){
            if( board[i][0] == board[i][1] && board[i][0] == board[i][2] ){
                if( board[i][0] == 'X'){
                    X_win = true;
                }
                else if( board[i][0] == 'O')
                    O_win = true;
                    
            }
            if( board[0][i] == board[1][i] && board[1][i] == board[2][i] ){
                if( board[0][i] == 'X'){
                    X_win = true;
                }
                else if( board[0][i] == 'O')
                    O_win = true;
                    
            }
                
        }
        if( board[0][0] == board[1][1] && board[1][1] == board[2][2] ){
                if( board[1][1] == 'X'){
                    X_win = true;
                }
                else if( board[1][1] == 'O')
                    O_win = true;
                    
        }
        if( board[0][2] == board[1][1] && board[1][1] == board[2][0] ){
                if( board[1][1] == 'X'){
                    X_win = true;
                }
                else if( board[1][1] == 'O')
                    O_win = true;
                    
        }
        if( X_win ==true && O_win==true)
            return false;
        if( X_win == true && abs( X - O) == 0 )
            return false;
        if( O_win == true && X > O )
            return false;
        return true;
    }
};