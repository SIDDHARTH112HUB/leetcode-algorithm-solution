//Link: https://leetcode.com/problems/spiral-matrix/ 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if( m == 0 ) return ans;
        int n = matrix[0].size();
        if( n == 0 ) return ans;
        int x = 0, y =0;
        int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
        int dir = 0;
        while(matrix[x][y]> INT_MIN){
            ans.push_back(matrix[x][y]);
            matrix[x][y] = INT_MIN;
            int nx = dx[dir%4] + x;
            int ny = dy[dir%4] + y;
            if( nx < 0 || ny < 0 || nx >=m || ny >=n || matrix[nx][ny] == INT_MIN ){
                ++dir;
            }
            nx = dx[dir%4] + x;
            ny = dy[dir%4] + y;
            if( nx < 0 || ny < 0 || nx >=m || ny >=n || matrix[nx][ny] == INT_MIN ){
                break;
            }
            x = nx;
            y = ny;
        }
        return ans;
    }
};