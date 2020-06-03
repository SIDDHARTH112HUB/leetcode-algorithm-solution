//Link: https://leetcode.com/problems/n-queens-ii/ 
class Solution {
public:
    
    bool check(vector<string> &board){
        //cout<<"begin "<<endl;
        for( int i = 0; i< board.size(); i++){
            int Q = 0;
            for( auto c:board[i]){
                if( c == 'Q')
                    Q++;
                if(Q > 1)
                    return false;
            }
            Q = 0;
            for( int j = 0; j<board.size(); j++){
                if( board[j][i] == 'Q')
                    Q++;
                if( Q > 1 )
                    return false;
            }
            Q = 0;
            int Q2 = 0;
            for(int j = 0; j<=i; j++){
                //cout<<i-j<<" "<<j<<" "<<endl;
                
                if( board[i-j][j] == 'Q' )
                    Q++;
                if( board[board.size()-1-i+j][board.size()-1-j] == 'Q' )
                    Q2++;
                if( Q > 1 || Q2>1 )
                    return false;
                    
            }
            //cout<<endl<<endl;
            Q = 0;
            Q2 = 0;
            for( int j = 0; j<=i; j++){
                //cout<<board.size()-1-i+j<<" "<<j<<" "<<endl;
                
                if( board[board.size()-1-i+j][j] == 'Q' )
                    Q++;
                if( board[j][board.size()-1-i+j] == 'Q' )
                    Q2++;
                if( Q > 1 || Q2>1 )
                    return false;
                    
            }
            //cout<<endl<<endl;
            
        }
        
        return true;
    }
    
    int totalNQueens(int n) {
        if( n <= 0) return 0;
        vector<string> board(n, string(n, '.') );
        int ans = 0;
        dfs(board, 0, ans);
        return ans;
    }
    bool dfs(vector<string> &board, int idx, int &ans){
        int n = board.size();
        if( idx >= n ){
            ++ans;
            return true;
        }
        for( int i = 0; i<n; i++){
            board[idx][i] ='Q';
            if( check(board) == true){
                dfs(board, idx+1, ans);
            }
            board[idx][i] ='.';
        }
        return false;
    }
};