//Link: https://leetcode.com/problems/sparse-matrix-multiplication/ 
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size();
        vector<vector<int> > ans(m, vector<int>(B[0].size()));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(A[i][j] == 0) continue;
                for(int k = 0; k < B[0].size(); ++k) {
                    ans[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return ans;
    }
};