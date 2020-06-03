//Link: https://leetcode.com/problems/alphabet-board-path/ 
class Solution {
public:
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    pair<int, int> getPos(char c) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if( board[i][j] == c)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
    string alphabetBoardPath(string target) {
        pair<int, int> p = { 0,  0};
        string ans ="";
        for( auto ch : target){
            auto next = getPos(ch);
            if( next == p){
                ans.push_back('!');
                continue;
            }
            
            if(ch == 'z'){
                int dy = next.second - p.second;
                char c = 'R';
                if( dy <  0)  c = 'L';
                for(int i = 0; i < abs(dy); ++i)
                    ans.push_back(c);
                    int dx = next.first - p.first;
                c = 'D';
                if(dx < 0) c = 'U';
                for(int i = 0; i < abs(dx); ++i)
                    ans.push_back(c);
            }else {
                int dx = next.first - p.first;
                char c = 'D';
                if(dx < 0) c = 'U';
                for(int i = 0; i < abs(dx); ++i)
                    ans.push_back(c);
                int dy = next.second - p.second;
                c = 'R';
                if( dy <  0)  c = 'L';
                for(int i = 0; i < abs(dy); ++i)
                    ans.push_back(c);
            }
            ans.push_back('!');
            
            p = next;
        }
        return ans;
    }
    
};