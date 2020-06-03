//Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/ 
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &p1, auto &p2){
            return p1[1] < p2[1];
        });
        int i = -1, ans = 0, j = 0, size = points.size();
        while(i < size && j < size) {
            if(i < 0 || points[j][0] > points[i][1] ) {
                i = j;
                ++ans;
            }
            ++j;
        }
        return ans;
    }
};