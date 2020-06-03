//Link: https://leetcode.com/problems/flatten-2d-vector/ 
class Vector2D {
public:
    int idx = 0;
    int idx2 = 0;
    vector<vector<int>> v;
    Vector2D(vector<vector<int>>& v) {
        this->v = v;
        while(idx < v.size() && v[idx].size() == 0) ++idx;
    }
    
    int next() {
        if(!hasNext()) return -1;
        int res = v[idx][idx2++];
        while(idx < v.size() && v[idx].size() <= idx2) {
            ++idx;
            idx2 = 0;
        }
        return res;
    }
    
    bool hasNext() {
        return v.size() > idx;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */