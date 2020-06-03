//Link: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/ 
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        int ans = 0;
        for(auto &row : matrix) {
            string s1, s2;
            for(auto i : row) {
                s1 += i == 1 ? '1' : '0';
                s2 += i == 1 ? '0' : '1';
            }
            ans = max(ans, ++m[s1]);
            ans =max(ans, ++m[s2]);
        }
        return ans;
    }
};