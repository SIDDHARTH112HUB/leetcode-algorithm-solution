//Link: https://leetcode.com/problems/design-excel-sum-formula/ 
class Excel {
public:
    int H;
    int W;
    map<pair<int, char>, vector<string> > m;
    
    vector<vector<int> > g;
    Excel(int H, char W) {
        m.clear();
        g.clear();
        this->H = H; this->W = W - 'A' + 1;
        g.resize(this->H, vector<int>(this->W));
    }
    
    void set(int r, char c, int v) {
        if (m.count({r, c})) m.erase({r, c});
        g[r - 1][c - 'A'] = v;
    }
    
    int get(int r, char c) {
        if (m.count({r, c})) return sum(r, c, m[{r, c}]);
        return g[r - 1][c - 'A'];
    }
    
    int sum(int r, char c, const vector<string> &strs) {
        int sum = 0;
        for(auto str : strs) {
            auto found = str.find_last_of(":");
            if(found == string::npos) {
                char y = str[0];
                int x = stoi(str.substr(1));
                sum += get(x, y);
            }else {
                int x = stoi(str.substr(1, (int)found - 1));
                char y = str[0];
                int x2 = stoi(str.substr(found + 2));
                char y2 = str[found + 1];
                for(int i = x; i <= x2; ++i) {
                    for(int j = y; j <= y2; ++j){
                        sum += get(i, j);
                    }
                }
            }
        }
        m[{r, c}] = strs;
        return sum;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 */