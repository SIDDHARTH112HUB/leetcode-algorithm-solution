//Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/ 

struct UF{
    int dup = 0;
    int group = 0;
    map<int, int> m;
    int find(int x) {
        if(m.count(x)) {
            if(m[x] == x) return x;
            return m[x] = find(m[x]);
        }
        ++group;
        return m[x] = x;
    }
    
    void combine(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b)
            ++dup;
        else{
            --group;
            m[b] = a;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UF uf;
        for(int i = 0; i < n; ++i)
            uf.find(i);
        for(auto &c : connections) {
            uf.combine(c[0], c[1]);
        }
        return (uf.dup + 1) >= uf.group ? uf.group - 1 : - 1;
    }
};