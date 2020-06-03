//Link: https://leetcode.com/problems/minesweeper/ 
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        h(board, x, y);
        return board;
    }
    
    void h(vector<vector<char>>& board, int x, int y) {
        if(board[x][y] != 'E') return;
        int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
        int dy[8] = {1, -1, 0, 1, -1, 0, -1, 1};
        int cnt = 0;
        for(int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) continue;
            cnt += (board[nx][ny] == 'M');
        }
        if(cnt > 0) {
            board[x][y] = cnt + '0';
            return;
        }
        board[x][y] = 'B';
        for(int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) continue;
            if(board[nx][ny] == 'E')
                h(board, nx, ny);
        }
    }
};