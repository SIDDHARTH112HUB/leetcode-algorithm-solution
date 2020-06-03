//Link: https://leetcode.com/problems/valid-boomerang/ 
class Solution {
public:
    bool isSame(vector<int> &v1, vector<int> &v2) {
        return v1[0] == v2[0] && v1[1] == v2[1];
    }
    bool isBoomerang(vector<vector<int>>& points) {
        auto p1 = points[0], p2 = points[1], p0 = points[2];
        if(isSame(p1, p2) || isSame(p0, p2) || isSame(p1, p0)) return  false;
        if(p1[1] == p2[1] || p0[1] == p2[1] || p0[1] == p1[1]) {
            return !(p1[1] == p2[1] && p1[1] == p0[1]);
        }
        double s1 = (p0[0] - p1[0]) * 1.0 / (p0[1] - p1[1]);
        double s2 = (p2[0] - p1[0]) * 1.0 / (p2[1] - p1[1]);
        return !(fabs(s1 - s2) < 0.000001);
    }
};