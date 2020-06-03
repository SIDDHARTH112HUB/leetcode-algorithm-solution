//Link: https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/ 
struct UF {
    int group = 0;
    unordered_map<int, int> m;
    int find(int p) {
        if(m.count(p)){
            if(m[p] != p)
                return m[p] = find(m[p]);
            return p;
        }
        m[p] = p;
        ++group;
        return p;
    }
    
    void combine(int a, int b) {
        int p1 = find(a);
        int p2 = find(b);
        if(p1 != p2){
            --group;
            m[p2] = p1;
        }
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        unordered_set<int> s;
        UF uf;
        sort(logs.begin(), logs.end());
        for(auto &log : logs) {
            int p1 = log[1];
            int p2 = log[2];
            int t = log[0];
            s.insert(p1);
            s.insert(p2);
            uf.combine(p1, p2);
            if(uf.group == 1 && s.size() == N)
                return t;
        }
        return -1;
    }
};