//Link: https://leetcode.com/problems/unique-paths-ii/ 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if( m == 0 ) return 0;
        int n = obstacleGrid[0].size();
        int grid[m][n];
        memset(grid, 0, sizeof(int)*m*n);
        for( int i = 0; i<m; i++)
        {
            if( obstacleGrid[i][0] == 1)
            {
                break;
            }
            else
                grid[i][0] = 1;
        }
        for( int i = 0; i<n; i++)
        {
            if( obstacleGrid[0][i] == 1)
            {
                break;
            }
            else
                grid[0][i] = 1;
        }
        for( int i = 1; i<m ;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1)
                    grid[i][j] = 0;
                else
                    grid[i][j] = grid[i-1][j] +grid[i][j-1];
            }
        }
        //delete[] grid;
        return grid[m-1][n-1];
    }
};