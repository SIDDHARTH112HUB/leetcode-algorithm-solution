//Link: https://leetcode.com/problems/frog-position-after-t-seconds/ 
class Solution {
public:
    vector<int> path;
    map<int, vector<int> > m;
    double ans = 1;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        for(auto &e : edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        cout<<"begin"<<endl;
        int depth = dfs(1, -1, target);
        cout<<depth<<" "<<path.size()<<endl;
        if(depth > t + 1) return 0;
        if(depth < t + 1 ) {
            if( m[target].size() - (t != 1) != 0)
                return 0;
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        
        for(auto n :  path) cout<<n<<" ";
        cout<<endl;
        
        dfs2(0, -1, t+1, target);
        return ans;
    }
    
    void dfs2(int idx, int p, int t, int target) {
        if(idx >= path.size()) {
            if(t == 0) return;
            if(m[path.back()].size() > (target != 1))
                ans = 0.0;
            return;
        }
        idx = min(idx, (int)path.size() - 1);
        if(t == 0) {
            if(path[idx] != target)
                ans = 0;
            return;
        }
        int len = (int)m[path[idx]].size() - (p != -1);
        if(len <= 0) return;
        //cout<<ans<<" "<<len<<endl;
        ans *= 1.0 / len;
        dfs2(idx + 1, 0, t - 1, target);
    }
    int dfs(int node, int p, int target) {
        if(node == target) return true;
        for(auto &next : m[node]) {
            if(next == p) continue;
            int res = dfs(next, node, target);
            if(res) {
                path.push_back(next);
                return res + 1;
            }
        }
        return false;
    }
};