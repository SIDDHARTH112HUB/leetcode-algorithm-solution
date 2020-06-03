//Link: https://leetcode.com/problems/line-reflection/ 
class Solution {
public:
    bool isReflected(vector<vector<int>>& _points) {
        set<vector<int> > dup;
        vector<vector<int> > points;
        for(auto &p : _points) {
            if(dup.count(p) == 0) {
                points.push_back(p);
                dup.insert(p);
            }
        }
        sort(points.begin(), points.end());
        sort(points.begin() + points.size() / 2, points.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int line = (points[0][0] + points.back()[0]);
        for(int i = 0; i <= points.size() / 2; ++i) {
            int j = points.size() - i - 1;
            if(points[i][1] == points[j][1] || points[i][0] == points[j][0]) {
                if(points[i][0] + points[j][0] != line)
                    return false;
            }else
                return false;
        }
        return true;
    }
};