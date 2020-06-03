//Link: https://leetcode.com/problems/optimize-water-distribution-in-a-village/ 
struct UF {
    unordered_map<int, int> m;
    int find(int x) {
        if(m.count(x)) {
            if(m[x] == x)
                return x;
            return m[x] = find(m[x]);
        }
        m[x] = x;
        return x;
    }
    
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            m[a] = b;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i = 0; i < wells.size(); ++i) {
            pipes.push_back({0, i + 1, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        UF uf;
        int ans = 0;
        for(int i = 0; i < pipes.size(); ++i) {
            auto pipe = pipes[i];
            int a = pipe[0], b = pipe[1], w = pipe[2];
            if(uf.merge(a, b)) {
                ans += w;
            }
        }
        return ans;
    }
};