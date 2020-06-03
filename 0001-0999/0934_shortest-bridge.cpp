//Link: https://leetcode.com/problems/shortest-bridge/ 
class Solution {
public:
    
    int shortestBridge(vector<vector<int>>& A) {
        vector< vector<int> > a, b;
        for( int i = 0; i < A.size(); i++){
            for( int j = 0; j < A[i].size(); j++){
                auto &group = a.size() == 0?a:b;
                if( A[i][j] == 1){
                    dfs(A, i, j, group);
                }
            }
        }
        int ans = INT_MAX;
        for( auto &pointA : a){
            for( auto &pointB : b){
                ans = min(ans, abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1])-1 );
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& A, int x, int y, vector<vector<int> > &group){
        int d[5] = {0,1,0,-1,0};
        int m = A.size();
        int n = A[0].size();
        A[x][y] = 0;
        group.push_back({x, y});
        for( int i = 0; i < 4; i++){
            int nx = x + d[i];
            int ny = y + d[i+1];
            if( nx >= 0 && ny >= 0 && nx < m && ny < n && A[nx][ny] == 1){
                dfs(A, nx, ny, group);
            }
        }
    }
};