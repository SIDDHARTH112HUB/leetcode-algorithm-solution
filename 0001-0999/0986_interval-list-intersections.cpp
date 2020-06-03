//Link: https://leetcode.com/problems/interval-list-intersections/ 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while(i < A.size() && j < B.size()) {
            int as = A[i][0], ae = A[i][1];
            int bs = B[j][0], be = B[j][1];
            int l = max(as, bs);
            int r = min(ae, be);
            if(l <= r) ans.push_back({l, r});
            if(ae > be) ++j;
            else if(ae < be) ++i;
            else ++i,++j;
        }
        return ans;
    }
};