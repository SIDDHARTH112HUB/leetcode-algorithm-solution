//Link: https://leetcode.com/problems/sort-the-matrix-diagonally/ 
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int> > arr(2*n + 2*m, vector<int>(2*n + 2 * m, INT_MAX));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j)
                arr[i][j] = mat[i][j];
        }
        for(int i = 0; i < max(m, n); ++i) {
            vector<int> a1, a2;
            for(int j = 0;j < min(n, m); ++j) {
                a1.push_back(arr[j][i + j]);
                a2.push_back(arr[i+j][j]);
            }
            sort(a1.begin(), a1.end());
            sort(a2.begin(), a2.end());
            int k = 0;
            for(int j = 0;j < min(n, m); ++j) {
                arr[j][i + j] = a1[k];
                arr[i+j][j] = a2[k++];
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j)
                mat[i][j] = arr[i][j];
        }
        return mat;
    }
};