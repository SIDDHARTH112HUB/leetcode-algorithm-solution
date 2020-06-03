//Link: https://leetcode.com/problems/check-if-it-is-a-straight-line/ 
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y = coordinates[0][1] - coordinates[1][1];
        double slope = y == 0 ? INT_MAX : 1.0 *(coordinates[0][0] - coordinates[1][0]) / y;
        for(int i = 2; i < coordinates.size(); ++i) {
            double dx = coordinates[i-1][0] - coordinates[i][0];
            double dy = coordinates[i-1][1] - coordinates[i][1];
            double sl = dy == 0 ? INT_MAX : dx / dy;
            if(fabs(sl - slope) > 0.000001) return false;
        }
        return true;
    }
};