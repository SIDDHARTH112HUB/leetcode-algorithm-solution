//Link: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/ 
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int> > arr(n, vector<int>(m));
        for(auto &ind : indices) {
            int x = ind[0], y = ind[1];
            for(int i = 0; i < m; ++i) {
                ++arr[x][i];
            }
            for(int i = 0; i < n; ++i) {
                ++arr[i][y];
            }
        }
        int ans = 0;
        for(auto &row : arr) {
            for(auto n : row)
                if(n %2) ++ans;
        }
        return ans;
    }
};