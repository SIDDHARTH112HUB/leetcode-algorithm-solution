//Link: https://leetcode.com/problems/surface-area-of-3d-shapes/ 
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        if( n == 0) return 0;
        int m = grid[0].size(); 
        if(m == 0 ) return 0;
        int ans = 0;
        for( int i = 0; i < n; i++){
            for( int j = 0; j < m; j++){
                int cur = grid[i][j];
                if( cur > 0 )
                    ans += (cur * 6 - ( cur - 1) * 2);
                
                if( j > 0 ){
                    int h = grid[i][j-1];
                
                    ans -= min(h, cur) *2;
                }
                if( i > 0 ){
                    int h = grid[i-1][j];
                    
                    ans -= min(h, cur) *2;
                }
            }
        }
        return ans;
    }
};