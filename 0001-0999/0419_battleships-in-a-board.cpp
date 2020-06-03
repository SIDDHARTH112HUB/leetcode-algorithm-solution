//Link: https://leetcode.com/problems/battleships-in-a-board/ 
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        if( m == 0 ) return 0;
        int n = board[0].size();
        if( n == 0 ) return 0;
        int ans = 0;
        for( int i = 0; i<m; i++){
            for( int j = 0; j<n; j++){
                bool flag = false;
                if( (i == 0 || board[i-1][j] == '.') && ( j==0 || board[i][j-1] =='.') && board[i][j]== 'X' )
                    ans++;
            }
        }
        return ans;
    }
};