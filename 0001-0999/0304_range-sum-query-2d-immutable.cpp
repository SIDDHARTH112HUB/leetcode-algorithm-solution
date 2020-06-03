//Link: https://leetcode.com/problems/range-sum-query-2d-immutable/ 
class NumMatrix {
public:
    vector<vector<int> > m;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix;
        for(int i = 0; i < m.size(); ++i)
            for(int j = 0; j < m[i].size(); ++j)
                m[i][j] = m[i][j] + (i ? m[i - 1][j] : 0) + (j ? m[i][j-1] : 0) - (i && j ? m[i-1][j-1] : 0);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m[row2][col2] - (row1 ? m[row1-1][col2]: 0) - (col1? m[row2][col1-1] : 0) + (row1 && col1 ? m[row1-1][col1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */