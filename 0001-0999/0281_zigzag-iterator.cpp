//Link: https://leetcode.com/problems/zigzag-iterator/ 
class ZigzagIterator {
public:
    int i[2];
    int t = 0;
    vector<vector<int> > v;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.resize(2);
        i[0] = 0;i[1] = 0;
        v[0] = v1;
        v[1] = v2;
    }

    int next() {
        if(hasNext() == false) return -1;
        if(v[t].size() <= i[t]){
            ++t;
            t %= 2;
            return next();
        }
        int turn = t++;
        t %= 2;
        return v[turn][i[turn]++];
    }

    bool hasNext() {
        return i[0] < v[0].size() || i[1] < v[1].size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */