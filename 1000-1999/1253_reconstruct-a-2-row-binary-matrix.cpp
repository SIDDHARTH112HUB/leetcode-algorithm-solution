//Link: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/ 
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int> > ans(2, vector<int>(colsum.size()));
        for(int i = 0; i < colsum.size(); ++i) {
            if(colsum[i] == 0) continue;
            if(colsum[i] == 2) {
                ans[0][i] = 1;
                ans[1][i] = 1;
                --upper;
                --lower;
                continue;
            }
            if(upper > lower) {
                --upper;
                ans[0][i] = 1;
                continue;
            }
            --lower;
            ans[1][i] = 1;
        }
        vector<vector<int> > d;
        return (upper == 0 && lower == 0) ? ans : d;
    }
};