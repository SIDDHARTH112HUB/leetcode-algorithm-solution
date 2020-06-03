//Link: https://leetcode.com/problems/friend-circles/ 
struct UF {
    unordered_map<int, int> m;
    int group = 0;
    int find(int x) {
        if(m.count(x)) {
            if(m[x] == x)
                return x;
            return m[x] = find(m[x]);
        }
        m[x] = x;
        ++group;
        return x;
    }
    
    bool combine(int a, int b) {
        a = find(a);
        b = find(b);
        if( a != b) {
            --group;
            m[b] = a;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UF uf;
        for(int i = 0; i < M.size(); ++i) {
            for(int j = i; j < M[i].size(); ++j) {
                if(M[i][j] == 1)
                    uf.combine(i, j);
            }
        }
        return uf.group;
    }
};