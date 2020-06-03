//Link: https://leetcode.com/problems/spiral-matrix-iii/ 
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int total = R*C;
        int dx[4] = { 0 , 1, 0, -1};
        int dy[4] = { 1 , 0, -1, 0};
        int cnt = 0;
        vector<vector<int> > ans;
        ans.push_back({r0, c0});
        while(total > ans.size() ){
            int step = cnt/2+1;
            for( int i = 1; i<=step;i++){
                r0 += dx[cnt%4];
                c0 += dy[cnt%4];
                if( r0 >= 0 && c0 >= 0 && r0 < R && c0 <C )
                    ans.push_back({r0,c0});
            }
            cnt++;
        }
        return ans;
    }
};