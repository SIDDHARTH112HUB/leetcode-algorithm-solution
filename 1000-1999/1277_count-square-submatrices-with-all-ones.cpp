//Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/ 
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            int sum = 0;
            for(int j = 0; j < matrix[i].size(); ++j) {
                int t = matrix[i][j];
                if(t == 1) ++ans;
                matrix[i][j] += sum + (i > 0 ? matrix[i-1][j] : 0);
                sum += t;
            }
        }
        int mx = min(matrix.size(), matrix[0].size());
        for(int k = 1; k < mx; ++k ) {
            for(int i = k; i < matrix.size(); ++i) {

                for(int j = k; j < matrix[i].size(); ++j) {
                    int num = matrix[i][j] - (i-k > 0 ? matrix[i-k-1][j]:0) - (j-k > 0 ? matrix[i][j-k-1]:0) + 
                        ((i-k > 0 && j-k > 0) ?matrix[i-k-1][j-k-1]:0);
                    if(num == (k+1) * (k+1)) ++ans;
                }
            }
        }
        return ans;
    }
};