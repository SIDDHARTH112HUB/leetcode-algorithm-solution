//Link: https://leetcode.com/problems/connecting-cities-with-minimum-cost/ 

struct UF {
    
    unordered_map<int, int> m;
    int group = 0;
    int find(int p) {
        if(m.count(p)) {
            if(m[p] == p)
                return p;
            m[p] = find(m[p]);
            return m[p];
        }
        m[p] = p;
        ++group;
        return p;
    }
    
    bool combine(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b) {
            m[b] = a;
            --group;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& conections) {
        //map<int, pair<int, int> > c;
        unordered_set<int> v;
        sort(conections.begin(), conections.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        int ans = 0;
        UF uf;
        for(auto &con: conections){
            int a = con[0], b = con[1];
            if(a==b) continue;
            //if(v.count(a) && v.count(b))
            //    continue;
            if(uf.combine(a, b))
                ans += con[2];
            v.insert(a);
            v.insert(b);
        }
        return v.size() == N && uf.group == 1? ans:-1;
    }
};