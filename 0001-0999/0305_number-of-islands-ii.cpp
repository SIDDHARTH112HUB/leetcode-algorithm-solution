//Link: https://leetcode.com/problems/number-of-islands-ii/ 

class Solution {
public:
    unordered_map<int, int> m;
    int group = 0;
    int find(int x) {
        if(m.count(x)) {
            if(m[x] == x) return x;
            return m[x] = find(m[x]);
        }
        ++group;
        return m[x] = x;
    }
    void combine(int x, int y) {
        x = find(x); y = find(y);
        if(x != y) {
            --group;
            m[x] = y;
        }
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        set<int> v;
        int d[5] = {0, 1, 0, -1, 0};
        for(auto p : positions) {
            int hash = (p[0] << 16) | p[1];
            find(hash);
            for(int i = 0; i < 4; ++i) {
                int nx = p[0] + d[i];
                int ny = p[1] + d[i + 1];
                if(nx < 0 || ny < 0) continue;
                int newHash = (nx << 16) | ny;
                if(v.count(newHash)) {
                    combine(hash, newHash);
                }
            }
            v.insert(hash);
            ans.push_back(group);
        }
        return ans;
    }
};