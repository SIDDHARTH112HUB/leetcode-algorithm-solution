//Link: https://leetcode.com/problems/count-servers-that-communicate/ 
class Solution {
public:
    int m;
    int n;
    int ans = 0;
    set<pair<int, int> > v;
    int countServers(vector<vector<int>>& grid) {
        
        m = grid.size(); 
        n = grid[0].size();
        vector<int> row(m), col(n);
        for(int i =0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1){
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }for(int i =0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if((row[i] > 1 || col[j] > 1) && grid[i][j] == 1)
                    v.insert({i, j});
            }
        }
        return v.size();
    }
};