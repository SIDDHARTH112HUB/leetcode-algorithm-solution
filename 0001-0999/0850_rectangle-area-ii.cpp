//Link: https://leetcode.com/problems/rectangle-area-ii/ 
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rs) {
        set<int> xs, ys;
        for(auto &r : rs) {
            xs.insert(r[0]);
            xs.insert(r[2]);
            ys.insert(r[1]);
            ys.insert(r[3]);
        }
        vector<int> ix(xs.begin(), xs.end());
        vector<int> iy(ys.begin(), ys.end());
        unordered_map<int, int> xm, ym;
        int idx = 0;
        for(auto n : xs) {
            xm[n] = idx++;
        }
        idx = 0;
        for(auto n : ys) {
            ym[n] = idx++;
        }
        bool grid[xs.size()+1][ys.size()+1];
        memset(grid, 0, sizeof(grid));
        for(auto &r : rs) {
            for(int i = xm[r[0]]; i < xm[r[2]]; ++i) {
                for(int j = ym[r[1]]; j < ym[r[3]]; ++j) {
                    grid[i][j] = true;
                }
            }
        }
        int i = 0, j = 0;
        long long ans = 0;
        for(int i = 0; i < xs.size(); ++i) {
            for(int j = 0; j < ys.size(); ++j) {
                if(grid[i][j] == true) {
                    ans += (long long)(ix[i + 1] - ix[i])  * (long long)(iy[j+1] - iy[j]);
                }
            }
        }
        return ans % 1000000007;
    }
};