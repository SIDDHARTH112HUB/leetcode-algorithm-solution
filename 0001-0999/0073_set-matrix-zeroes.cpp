//Link: https://leetcode.com/problems/set-matrix-zeroes/ 
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool row0_zero = false;
        bool column0_zero = false;
        bool lastrow_zero = false;
        int ROW = matrix.size();
        int COL = matrix[0].size();
        for(int i = 0; i < COL; ++i)  
            if (matrix[0][i] == 0)  
            {  
                row0_zero = true;  
                break;  
            }  
        for(int i = 0; i < ROW; ++i)  
            if (matrix[i][0] == 0)  
            {  
                column0_zero = true;  
                break;  
            }  
            
        for( int i = 0; i <matrix.size(); i++)
        {
            vector<int>& row = matrix[i];
            for( int j = 0; j<row.size(); j++ )
            {
                if( row[j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < ROW; ++i)  
            if (matrix[i][0] == 0)  
                for(int j = 1; j < COL; ++j)  
                    matrix[i][j] = 0;  
          
        for(int i = 1; i < COL; ++i)  
            if (matrix[0][i] == 0)  
                for(int j = 1; j < ROW; ++j)  
                    matrix[j][i] = 0;  
        if (row0_zero)  
            fill(begin(matrix[0]), end(matrix[0]), 0);  
        if (column0_zero)  
            for(int i = 0; i < ROW; ++i)  
                matrix[i][0] = 0;  
    }
};