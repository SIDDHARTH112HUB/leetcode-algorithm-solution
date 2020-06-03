//Link: https://leetcode.com/problems/transform-to-chessboard/ 
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int N = board.size();
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j]) return -1;
            }
        }
        int rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;
        for(int i = 0; i < board.size(); ++i) {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowDiff += (board[i][0] == i % 2);
            colDiff += (board[0][i] == i % 2);
        }
        if(rowSum > (N + 1) / 2 || rowSum < N / 2) return -1;
        if(colSum > (N + 1) / 2 || colSum < N / 2) return -1;
        if(N % 2) {
            if (rowDiff % 2)rowDiff = N - rowDiff;
            if (colDiff % 2)colDiff = N - colDiff;
        }else{
            rowDiff = min(N - rowDiff, rowDiff);
            colDiff = min(N - colDiff, colDiff);
        }
        return (rowDiff + colDiff)/2;
    }
};