//Link: https://leetcode.com/problems/search-a-2d-matrix-ii/ 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int i = 0, j = matrix[0].size()-1;
        while( i < matrix.size() && j >= 0) {
            int n = matrix[i][j];
            if(n == target)
                return true;
            else if(n > target)
                j--;
            else
                i++;
        }
        return false;
    }
};