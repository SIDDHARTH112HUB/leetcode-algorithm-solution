//Link: https://leetcode.com/problems/shortest-distance-to-target-color/ 
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<set<int>> col(4);
        for(int i = 0; i < colors.size(); ++i) {
            int c = colors[i];
            col[c].insert(i);
        }
        vector<int> ans;
        for(auto &q : queries) {
            int idx = q[0];
            int c = q[1];
            auto it = col[c].lower_bound(idx);
            if(it == col[c].end()) {
                if(it == col[c].begin()) {
                    ans.push_back(-1);
                    continue;
                }
                --it;
            }
            int r = *it;
            int l = - 10000000;
            if(it != col[c].begin()){
                --it;
                l = *it;
            }
            int res = abs(r-idx) > abs(l - idx) ? abs(l - idx) : abs(r-idx);
            ans.push_back(res);
        }
        return ans;
    }
};