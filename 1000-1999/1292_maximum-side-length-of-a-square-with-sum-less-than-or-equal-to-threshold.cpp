//Link: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ 
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        for(int i = 0; i < mat.size(); ++i) {
            int sum = 0;
            for(int j = 0; j < mat[0].size(); ++j) {
                int src = mat[i][j];
                mat[i][j] += sum + (i > 0 ? mat[i-1][j] :0);
                sum += src;
            }
        }
        int side = min(mat.size(), mat[0].size());
        int ans = -1;
        for(int k = side-1; k >=0; --k) {
            for(int i = k; i < mat.size(); ++i) {
                for(int j = k; j < mat[0].size(); ++j) {
                    int sum = mat[i][j] + ((i-k-1 > 0 && j-k-1 > 0 )?mat[i - k -1][j-k-1] : 0)  - (i - k - 1 > 0 ? mat[i-k-1][j] : 0) - (j-k-1> 0 ? mat[i][j-k-1] : 0);
                    if(sum <= threshold)
                        ans = max(sum, ans);
                }
            }
            if( ans >= 0)
                return k + 1;
        }
        return 0;
    }
};