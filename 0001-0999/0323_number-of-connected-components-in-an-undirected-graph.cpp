//Link: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/ 
class Solution {
public:
    map<int, int> m;
    int group = 0;
    int find(int x) {
        if(m.count(x)) return m[x] == x ? x : (m[x] = find(m[x]));
        ++group;
        return m[x] = x;
    }
    void combine(int a, int b) {
        if((a = find(a)) != (b = find(b))) {
            --group;
            m[a] = b;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; ++i) find(i);
        for(auto &e : edges) 
            combine(e[0], e[1]);
        return group;
    }
};