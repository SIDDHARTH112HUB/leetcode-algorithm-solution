//Link: https://leetcode.com/problems/matrix-cells-in-distance-order/ 
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        queue<pair<int, int> > q;
        set<pair<int, int> > v;
        q.push({r0, c0});
        vector<vector<int> > ans;
        ans.push_back({r0, c0});
        v.insert({r0, c0});
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()){
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    int nx = p.first + d[i];
                    int ny = p.second + d[i+1];
                    if(nx < 0 || ny < 0 || nx >= R || ny >= C || v.count({nx, ny})) continue;
                    v.insert({nx, ny});
                    q.push({nx, ny});
                    ans.push_back({nx, ny});
                }
            }
        }
        return ans;
    }
};