//Link: https://leetcode.com/problems/snakes-and-ladders/ 
class Solution {
public:
    int N;
    pair<int, int> getPos(int pos){
        pos -= 1;
        return {pos / N, pos%N};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        N = board.size();
        for( int i = 1; i<N; i+=2){
            reverse(board[i].begin(), board[i].end());
        }
        int end = N*N;
        queue<int> q;
        q.push(1);
        unordered_set<int> visited;
        int steps = 0;
        while( q.size() > 0 ){
            int size = q.size();
            while( size-- > 0 ){
                int idx = q.front();
                q.pop();
                if( idx == end ) return steps;
                for( int i = 1; i<= 6; i++){
                    if( idx + i > end ) continue;
                    int new_idx = idx + i;
                    auto pos = getPos(idx+i);
                    int val = board[pos.first][pos.second];
                    if( val > 0 )
                        new_idx = val;
                    if( visited.count(new_idx) ) continue;
                    q.push(new_idx);
                    visited.insert(new_idx);    
                }
            }
            steps++;
        }
        return -1;
    }
};