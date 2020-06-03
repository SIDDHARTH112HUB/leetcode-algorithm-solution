//Link: https://leetcode.com/problems/diagonal-traverse/ 
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int x = 0, y = 0;
        int dx = -1, dy = 1;
        int m = matrix.size();
        if(m <= 0) return {};
        int n = matrix[0].size();
        if(n <= 0) return {};
        vector<int> ans;
        while(ans.size() < m* n) {
            ans.push_back(matrix[x][y]);
            x += dx;
            y += dy;
            if(x >= m) { x = m - 1; y += 2; swap(dx, dy);}
            if(y >= n) { y = n - 1; x += 2; swap(dx, dy);}
            if(x < 0) { x = 0; swap(dx, dy);}
            if(y < 0) { y = 0; swap(dx, dy);}
        }
        return ans;
    }
};