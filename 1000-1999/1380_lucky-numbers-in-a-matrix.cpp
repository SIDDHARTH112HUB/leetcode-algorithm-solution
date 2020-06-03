//Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/ 
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int f = true;
                int num  = matrix[i][j];
                for(int k = 0; k < m; ++k) {
                    if(matrix[k][j] > num) {
                        f = false;break;
                    }
                }
                for(int k = 0; k < n; ++k) {
                    if(matrix[i][k] < num) {
                        f = false;break;
                    }
                }
                if(f ) ans.push_back(num);
            }
        }
        return ans;
    }
};