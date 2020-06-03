//Link: https://leetcode.com/problems/toeplitz-matrix/ 
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        for(int i = 0; i<M; i++){
            int j = 0;
            
            int src = matrix[i+j][j];
            
            while( i+j < M && j < N ){
                if( matrix[i+j][j] != src )
                    return false;
                j++;
            }
            j=0;
            if( i+j >= N )continue;
            src = matrix[j][i+j];
            while( i+j < N && j < M ){
                if( matrix[j][j+i] != src )
                    return false;
                j++;
            }
            
        }
        return true;
    }
};