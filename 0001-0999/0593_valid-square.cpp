//Link: https://leetcode.com/problems/valid-square/ 
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> m;
        vector<vector<int> > ps = {p1, p2, p3, p4};
        for(int i = 0; i < 4; ++i) {
            for(int j = i+1; j < 4; ++j) {
                auto &a = ps[i], &b = ps[j];
                ++m[(a[1] - b[1]) * (a[1] - b[1]) + (a[0] - b[0]) * (a[0] - b[0])];
            }
        }
        return m.size() == 2 && m[0] == 0;
    }
};