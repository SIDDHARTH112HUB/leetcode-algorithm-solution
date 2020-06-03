//Link: https://leetcode.com/problems/kill-process/ 
class Solution {
public:
    map<int, vector<int> > g;
    vector<int> ans;
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        for(int i = 0; i < pid.size(); ++i) {
            g[ppid[i]].push_back(pid[i]);
        }
        dfs(kill);
        return ans;
    }
    
    void dfs(int id) {
        ans.push_back(id);
        for(auto next : g[id]) {
            dfs(next);
        }
    }
};