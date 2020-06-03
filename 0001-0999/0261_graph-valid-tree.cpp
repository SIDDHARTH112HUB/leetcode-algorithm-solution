//Link: https://leetcode.com/problems/graph-valid-tree/ 
class Solution {
public:
    map<int, int> u;
    int group = 0;
    int find(int x) {
        if(u.count(x)){
            if(u[x] == x) return x;
            return u[x] = find(u[x]);
        }
        ++group;
        return u[x] = x;
    }
    
    bool combine(int a, int b) {
        a = find(a); b = find(b);
        if(a != b) {
            u[a] = b;
            --group;
        }
        return a != b;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n == 1 && edges.size() == 0) return true;
        int cnt = 0;
        for(auto e : edges) {
            if(!combine(e[0], e[1]))
                return false;
        }
        return edges.size() == n - 1 && group == 1;
    }
};