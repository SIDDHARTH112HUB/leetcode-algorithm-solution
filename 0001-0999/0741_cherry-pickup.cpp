//Link: https://leetcode.com/problems/cherry-pickup/ 
class Solution {
public:
    int n;
    vector<vector<vector<int>>> m;
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, helper(grid,0,0,0));
    }
    int helper(vector<vector<int>>& grid, int x1, int y1, int x2){
        int y2 = x1+y1 - x2;
        if( x1 >= n || y1 >=n || x2 >= n || y2>=n )
            return -1;
        
        if( grid[x1][y1] < 0 || grid[x2][y2] < 0 ) return -1;
        if( x1 == n-1 && y1==n-1) return grid[x1][y1];
        int memo = m[x1][y1][x2];
        if( memo != INT_MIN ) return memo;
        int ans = max( max(helper(grid, x1+1, y1, x2), helper(grid, x1, y1+1, x2) ), 
                       max(helper(grid, x1+1, y1, x2+1), helper(grid, x1, y1+1, x2+1) ) );
        if( ans < 0 ){
            m[x1][y1][x2] = -1;
            return -1;
        }
        ans += grid[x1][y1];
        if( x1 != x2 )
            ans += grid[x2][y2];
        m[x1][y1][x2] = ans;
        return ans;
    }
};