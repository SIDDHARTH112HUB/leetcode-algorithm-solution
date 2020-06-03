//Link: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/ 
class Solution {
public:
    
    int check(vector<vector<int> > &g) {
        for(int i = 0; i < 3; ++i) {
            if(g[i][0] == g[i][1] && g[i][1] == g[i][2] && g[i][1] > 0)
                return g[i][0];
            if(g[0][i] == g[1][i] && g[1][i] == g[2][i] && g[1][i] > 0)
                return g[0][i];
        }
        if(g[0][0] == g[1][1] && g[1][1] == g[2][2] && g[1][1] > 0) return g[1][1];
        if(g[2][0] == g[1][1] && g[1][1] == g[0][2] && g[1][1] > 0) return g[1][1];
        return 0;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int> > g(3, vector<int>(3));
        int s = 0;
        for(auto &m : moves) {
            g[m[0]][m[1]] = (s % 2) + 1;
            int res = check(g);
            if( res > 0)
                return res == 1 ? "A" : "B";
            ++s;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};