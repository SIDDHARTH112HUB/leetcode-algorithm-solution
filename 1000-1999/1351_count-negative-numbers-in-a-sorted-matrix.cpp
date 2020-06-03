//Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/ 
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto &row : grid) {
            for(auto n : row)
                ans += n < 0;
        }
        return ans;
    }
};