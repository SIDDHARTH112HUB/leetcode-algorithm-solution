//Link: https://leetcode.com/problems/candy-crush/ 
const bool DEBUG = false;
void print(vector<vector<int>>& board) {
    if(!DEBUG) return;for(auto c : board) {for(auto n : c)cout<<n<<"\t";cout<<endl;}cout<<endl;
}
void print(vector<int>& row) {
    if(!DEBUG) return;for(auto c : row) {cout<<c<<"\t";}cout<<endl;
}
class Solution {
public:
    void fall(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int j = 0; j < n; ++j) {
            int k = m - 1, i = m - 1;
            while(i >= 0){
                k = min(k, i - 1);
                if(board[i][j] == 0) {
                    while(k >= 0 && board[k][j] == 0)
                        --k;
                    if(k < 0) break;
                    swap(board[i][j], board[k][j]);
                }
                --i;
            }
        }
    }
    
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        print(board);
        while(true) {
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j <n; ++j) {
                    if(board[i][j] > 0) {
                        int cnt = 0;
                        set<pair<int, int> > v;
                        dfs(board, i, j, abs(board[i][j]), 0, 1, cnt, v);
                        v.clear();
                        cnt = 0;
                        dfs(board, i, j, abs(board[i][j]), 1, 0, cnt, v);
                    }
                }
            }
            bool f = true;
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j <n; ++j){
                    if(board[i][j] < 0) {
                        board[i][j] = 0;
                        f = false;
                    }
                }
            }
            print(board);
            fall(board);
            print(board);
            if(f) break;
        }
        return board;
    }
    
    void dfs(vector<vector<int>>& board, int x, int y, int val, int dx, int dy, int &cnt, set<pair<int, int> > &v) {
        int m = board.size(), n = board[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || v.count({x, y}) || abs(board[x][y]) != abs(val)) return;
        v.insert({x, y});
        ++cnt;
        dfs(board, x + dx, y + dy, val, dx, dy, cnt, v);
        dfs(board, x - dx, y - dy, val, dx, dy, cnt, v);
        if(cnt >= 3)
            board[x][y] = -val;
        
    }
};