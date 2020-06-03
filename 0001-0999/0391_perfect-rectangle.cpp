//Link: https://leetcode.com/problems/perfect-rectangle/ 
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int > > m;
        long long area = 0;
        for(auto &r :rectangles) {
            pair<int, int> p1 = {r[0], r[1]};
            pair<int, int> p2 = {r[0], r[3]};
            pair<int, int> p3 = {r[2], r[1]};
            pair<int, int> p4 = {r[2], r[3]};
            for(auto &p :{p1, p2, p3, p4}) {
                const auto &r = m.insert(p);
                if(!r.second) {
                    m.erase(r.first);
                }
            }
            area += (r[2] - r[0]) * ( r[3] - r[1]);
        }
        if(m.size() != 4) return false;
        int mnx = INT_MAX, mny = INT_MAX, mxx = 0, mxy = 0;
        for(auto p : m) {
            mxx = max(p.first, mxx);
            mnx = min(p.first, mnx);
            mxy = max(p.second, mxy);
            mny = min(p.second, mny);
        }
        return area == (mxx- mnx) * (mxy - mny);
    }
};
