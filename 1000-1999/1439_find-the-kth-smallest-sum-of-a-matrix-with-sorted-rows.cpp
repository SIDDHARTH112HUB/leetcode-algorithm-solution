//Link: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/ 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row = mat[0];
        for(int i = 1; i < mat.size(); ++i) {
            vector<int> nr;
            for(int j = 0; j < mat[i].size(); ++j)
                for(auto n : row)
                    nr.push_back(mat[i][j] + n);
            sort(nr.begin(), nr.end());
            int size = min(k, int(nr.size()));
            if(row.size() != size) row.resize(size);
            copy(nr.begin(), nr.begin() + size, row.begin());
        }
        return row[k-1];
    }
};