//Link: https://leetcode.com/problems/magic-squares-in-grid/ 
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        if( n < 3 ) return 0;
        int m = grid[0].size();
        if( m < 3 ) return 0;
        int ans = 0;
        int check[10] = {0};
        for( int i = 0;i < n-2; i++ ){
            for( int j = 0; j<m-2; j++ ){
                int sum = grid[i][j] + grid[i+1][j+1]+grid[i+2][j+2];
                int sum2 = grid[i+2][j] + grid[i+1][j+1]+grid[i][j+2];
                if( sum != sum2)
                    continue;
                bool flag = false;
                memset(check, 0, sizeof(int) *10);
                for( int k = 0; k<3;k ++){
                    
                    if (( grid[i+k][j] >9 || grid[i+k][j] < 1) || ( grid[i+k][j+1] >9 || grid[i+k][j+1] < 1) ||
                            ( grid[i+k][j+2] >9 || grid[i+k][j+2] < 1) ){
                        flag = true;
                        //printf("grid check i:%d j:%d \n", i, j );
                        break;
                    }
                    
                    if( check[grid[i+k][j]] || check[grid[i+k][j+1]] || check[grid[i+k][j+2]] ){
                        //printf(" check array i:%d j:%d \n", i, j );
                        flag = true;
                        break;
                    }else{
                        check[grid[i+k][j]] = 1;
                        check[grid[i+k][j+1]] =1;
                        check[grid[i+k][j+2]] =1;
                    }
                    int num = grid[i][j+k] + grid[i+1][j+k]+grid[i+2][j+k];
                    
                    if( num != sum ){
                        //printf(" check column i:%d j:%d \n", i, j );
                        flag = true;
                        break;
                    }
                    num = grid[i+k][j] + grid[i+k][j+1]+grid[i+k][j+2];
                    if( num != sum ){
                        //printf(" check row i:%d j:%d \n", i, j );
                        flag = true;
                        break;
                    }
                }
                if( !flag )
                    ans++;
            }
        }
        return ans;
    }
};