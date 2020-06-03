//Link: https://leetcode.com/problems/range-sum-query-2d-mutable/ 
class NumMatrix {
public:
    vector<vector<int> > mat;
    vector<vector<int> > bit;
    int m;
    int n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0) return;
        n = matrix[0].size();
        mat.resize(m+1, vector<int>(n+1));
        bit.resize(m+1, vector<int>(n+1));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int d = val - mat[row+1][col+1];
        for(int i = row + 1; i <= m; i += i & -i) {
            for(int j = col + 1; j <=n; j += j & -j) {
                bit[i][j] += d;
            }
        }
        mat[row+1][col+1] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) + getSum(row1 - 1, col1 - 1) - getSum(row2, col1-1) - getSum(row1-1, col2);
    }
    
    int getSum(int row, int col) {
        int sum = 0;
        for(int i = row + 1; i > 0; i -= i & -i) {
            for(int j = col + 1; j > 0; j -= j & -j) {
                sum += bit[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */