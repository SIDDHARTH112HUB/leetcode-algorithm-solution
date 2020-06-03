//Link: https://leetcode.com/problems/course-schedule-iv/ 

class Solution {
public:
    bool g[101][101];
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        memset(g, 0, sizeof(g));
        for(auto &p : prerequisites) {
            g[p[0]][p[1]] = true;
        }
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
        vector<bool> ans;
        for(auto &q : queries) {
            ans.push_back(g[q[0]][q[1]]);
        }
        return ans;
    }
};
