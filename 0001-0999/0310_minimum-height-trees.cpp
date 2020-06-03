//Link: https://leetcode.com/problems/minimum-height-trees/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > g;
    unordered_set<int> v;
    vector<int> ans;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(auto &e :edges) {
            g[e[0]][e[1]] = 1;
            g[e[1]][e[0]] = 1;
        }
        dfs(0);
        /*for(auto it : g) {
            for(auto it2 : it.second) {
                cout<<it.first<<"--->"<<it2.first<<" d:"<<it2.second<<endl;
            }
        }*/
        helper(0);
        return ans;
    }
    
    int helper(int i) {
        int mx = 0, mxp = -1;
        for(auto it : g[i]) {
            if(it.second > mx) {
                mx = it.second;
                mxp = it.first;
            }
        }
        int sx = 0, sxp = -1;
        for(auto it: g[i]) {
            if(it.second > sx && it.first != mxp) {
                sx = it.second;
                sxp = it.first;
            }
        }
        if(mx == sx) {
            ans = {i};
            return 0;
        }
        if(mx - sx == 1) {
            ans = {i, mxp};
            return 0;
        }
        g[mxp][i] = g[i][mxp] = sx + 1;
        return helper(mxp);
    }
    
    int dfs(int i) {
        if(v.count(i)) return 0;
        v.insert(i);
        int mx = 0;
        for(auto &it : g[i]) {
            if(v.count(it.first)) continue;
            int h = 1 + dfs(it.first);
            g[i][it.first] = h;
            g[it.first][i] = h;
            mx = max(mx, h);
        }
        return mx;
    }
};