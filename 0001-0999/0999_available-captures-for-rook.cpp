//Link: https://leetcode.com/problems/available-captures-for-rook/ 
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        int m = board.size(); 
        int n = board[0].size();
        int x = 0,y = 0;
        for( x = 0; x < m; x++){
            int flag = 0;
            for( y = 0; y < n; y++){
                if( board[x][y] == 'R'){
                    flag = true;
                    break;
                }
                    
            }
            
            if( flag == true )
                break;
        }
        int d[5] = {0,1,0,-1,0};
        
        for( int j = 0; j < 4; j++){
            for( int i = 1; i <= 8; i++){
                int nx = x + d[j]*i;
                int ny = y + d[j+1]*i;
                if( nx < 0 || ny < 0 || nx >=m || ny >=n )
                    break;
                if( board[nx][ny] == '.')
                    continue;
                if( board[nx][ny] == 'p')
                    ans++;
                break;
            }
        }
        return ans;
        
    }
};