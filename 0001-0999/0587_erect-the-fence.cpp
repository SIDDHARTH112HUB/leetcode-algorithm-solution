//Link: https://leetcode.com/problems/erect-the-fence/ 
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<vector<int> > res;
        sort(points.begin(), points.end(), [](auto &a, auto &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for(auto p : points ) {
            while(res.size() >= 2 && orient(res[res.size()-2], res.back(), p) < 0)
                res.pop_back();
            res.push_back(p);
        }
        for(int i = points.size()-2; i >=0; --i) {
            while(res.size() >= 2 && orient(res[res.size()-2], res.back(), points[i]) < 0) {
                res.pop_back();
            }
            res.push_back(points[i]);
        }
        set<vector<int> > s(res.begin(), res.end());
        return vector<vector<int> > (s.begin(), s.end());
    }
    
    int orient(vector<int> &p, vector<int> &q, vector<int> &r) {
        return (q[1] - p[1]) * (r[0] - p[0]) - (r[1] - p[1]) * (q[0] - p[0]);
    }
};