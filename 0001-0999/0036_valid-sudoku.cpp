//Link: https://leetcode.com/problems/valid-sudoku/ 
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int h[9];
        int row = board.size();
        int col = board[0].size();
        for( vector<vector<char> >::iterator iter=board.begin(); iter!=board.end(); ++iter)
        {
            memset( h, 0, sizeof(int)*9 );
            for( vector<char>::iterator ic = (*iter).begin(); ic!=(*iter).end(); ++ic )
            {
                char c = *ic;
                if( c == '.' ) continue;
                if( (h[c-'1']++)>=1)return false;
            }
        }
        for( int i = 0; i<col; i++)
        {
            memset( h, 0, sizeof(int)*9 );
            for( int j = 0; j<row;j++)
            {
                char c = board[j][i];
                if( c == '.' )continue;
                if( (h[c-'1']++)>=1)return false;
            }
        }
        for( int i=0; i<3; i++)
        {
           
            for( int j=0;j<3;j++)
            {
                 memset( h, 0, sizeof(int)*9 );
                for( int k=0; k<9;k++)
                {
                    char c = board[i*3+k/3][j*3+k%3];
                    if( c == '.')continue;
                    if( (h[c-'1']++)>=1)return false;
                }
            }
        }
        return true;
    }
}; 