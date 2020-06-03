//Link: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/ 
class Solution {
public:
    int hash(vector<vector<int>>& mat) {
        int n = 0;
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0;j < mat[i].size(); ++j){
                n |= mat[i][j] << (i*mat.size()+j);
            }
        }
        return n;
    }
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<vector<vector<int> > > q;
        set<int> v;
        q.push(mat);
        v.insert(hash(mat));
        int step = 0;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto mt = q.front();
                
                q.pop();
                
                if(hash(mt) == 0) return step;
                for(int i = 0; i < mat.size(); ++i) {
                    for(int j = 0; j < mat[i].size(); ++j) {
                        auto newm = mt;
                        newm[i][j] = !mt[i][j];
                        for(int k = 0; k < 4; ++k) {
                            int nx = i + d[k];
                            int ny = j + d[k + 1];
                            if(nx < 0 || ny < 0 || nx >= m || ny >= n )continue;
                            newm[nx][ny] = !newm[nx][ny];
                        }
                        int nh = hash(newm);
                        if(v.count(nh)) continue;
                        q.push(newm);
                        v.insert(nh);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};