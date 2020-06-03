//Link: https://leetcode.com/problems/escape-a-large-maze/ 
#define h(x, y) (((x) << 16) | (y))
class Solution {
public:
    map<int, int> x;
    map<int, int> y;
    void add(vector<int> &p, int val) {
        for(int i = -1; i <= 1; ++i) {
            int nx = p[0] + i, ny = p[1] + i;
            if(nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000) continue;
            if(x.count(nx) == 0 || val)
                x[nx] = i == 0 ? val : 0;
            if(y.count(ny) == 0 || val)
                y[ny] = i == 0 ? val : 0;
        }   
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto &b : blocked)
            add(b, 1);
        add(source, 0);
        add(target, 0);
        vector<vector<int> > g;
        for(auto &ix : x) {
            int xv = (ix.second = g.size());
            g.push_back({});
            for(auto &iy : y) {
                int yv = (iy.second = g.back().size());
                int val = xv == yv ? xv : 0;
                g.back().push_back(0);
            }
        }
        
        queue<vector<int> > q;
        unordered_map<int, int> v;
        for(auto &b: blocked) {
            int hash = h(x[b[0]], y[b[1]]);
            v[hash] = 1;
        }
        source = {x[source[0]], y[source[1]]};
        target = {x[target[0]], y[target[1]]};
        q.push(source);
        q.push(target);
        v[h(source[0], source[1])] = 2;
        v[h(target[0], target[1])] = 3;
        
        //cout<<"source: "<<source[0]<<" "<<source[1]<<endl;
        //cout<<"target: "<<target[0]<<" "<<target[1]<<endl;
        cout<<g.size()<<" "<<g[0].size()<<endl;
        int cnt = 0;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                q.pop();
                int dx = p[0];
                int dy = p[1];
                int curHash = h(dx, dy);
                for(int i = 0; i < 4; ++i) {
                    int nx = dx + d[i];
                    int ny = dy + d[i+1];
                    if(nx < 0 || ny < 0 || nx >= g.size() || ny >= g[0].size()) continue;
                    int hash = h(nx, ny);
                    int hashValue = v[hash];
                    if(hashValue == 1 || hashValue == v[curHash]) continue;
                    if(hashValue >=2 && hashValue != v[curHash]){
                        return true;
                    }
                    q.push({nx, ny});
                    v[hash] = v[curHash];
                }
            }
        }
        return false;
    }
};

