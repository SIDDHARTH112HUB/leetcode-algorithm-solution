//Link: https://leetcode.com/problems/number-of-enclaves/ 
class Solution {
public:
    int m;
    int n;
    int numEnclaves(vector<vector<int>>& A) {
        m = A.size();
        n = A[0].size();
        for (int i = 0; i < m; i++) {
            if(A[i][0] == 1)
                solve(A, i, 0);
            if(A[i][n-1] == 1)
                solve(A, i, n-1);
        }
        for (int i = 0; i < n; i++) {
            if (A[0][i] == 1)
                solve(A, 0, i);
            if (A[m-1][i] == 1)
                solve(A, m-1, i);
        }
        int ans = 0;
        for(auto &row:A)
            for( int n : row )
                if(n==1) ans++;
        return ans;
    }
    
    void solve(vector<vector<int>>& A, int x, int y) {
        if (x >= m || y >= n || x <0 || y < 0 || A[x][y] == 0)
            return;
        A[x][y] = 0;
        solve(A, x+1, y);
        solve(A, x, y+1);
        solve(A, x, y-1);
        solve(A, x-1, y);
    }
};