//Link: https://leetcode.com/problems/projection-area-of-3d-shapes/ 
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size();
        
        if( m == 0 ) return 0;
        int n = grid[0].size();
        if( n == 0 ) return 0;
        int ans = 0;
        for( int i = 0; i<m; i++){
            ans += *max_element(grid[i].begin(), grid[i].end());
            int col_max = 0;
            for( int j = 0; j<n; j++){
                if( grid[i][j] > 0 )
                    ans++;
                if( grid[j][i] > col_max ){
                    col_max = grid[j][i];
                }
            }
            ans+= col_max;
        }
        return ans;
    }
};