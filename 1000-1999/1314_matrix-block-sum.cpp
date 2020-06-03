//Link: https://leetcode.com/problems/matrix-block-sum/ 
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; ++i) {
            int sum = 0;
            for(int j = 0; j < n; ++j) {
                int t = mat[i][j];
                mat[i][j] += (i > 0 ? mat[i-1][j] : 0) + sum;
                //cout<<mat[i][j]<<" ";
                sum += t;
            }
            //cout<<endl;
        }
        vector<vector<int> > ans(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int lx = max(i - K, 0), rx = min(m-1, i + K);
                int ly = max(j - K, 0), ry = min(n-1, j + K);
                ans[i][j] = mat[rx][ry] + ((lx > 0 && ly> 0) ? mat[lx-1][ly-1]:0) - (ly > 0 ? mat[rx][ly-1]:0) - (lx > 0 ? mat[lx-1][ry]:0);
            }
        }
        return ans;
    }
};