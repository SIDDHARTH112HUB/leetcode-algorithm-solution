//Link: https://leetcode.com/problems/minimum-path-sum/ 
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if( m == 0 ) return 0;
        int n = grid[0].size();
        int a[m][n];
        a[0][0] = grid[0][0];
        for( int i = 1; i< m ; i++ )
        {
            a[i][0] = grid[i][0] + a[i-1][0];
        }
        for( int i = 1; i< n ; i++ )
        {
            a[0][i] = grid[0][i] + a[0][i-1];
        }
        for( int i = 1; i < m; i++)
        {
            for( int j = 1; j < n; j++)
            {
                int num1 = a[i-1][j] + grid[i][j];
                int num2 = a[i][j-1] + grid[i][j];
                a[i][j] = num1 > num2? num2:num1;
            }
        }
        return a[m-1][n-1];
    }
};