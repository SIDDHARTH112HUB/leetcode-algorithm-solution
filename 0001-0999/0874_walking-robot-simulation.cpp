//Link: https://leetcode.com/problems/walking-robot-simulation/ 
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, dir = 0;
        int dy[4] = {1, 0, -1, 0};
        int dx[4] = {0, 1, 0, -1};
        unordered_map<int, unordered_set<int> > m;
        for( auto o: obstacles){
            m[o[0]].insert(o[1]);
        }
        int ans = 0;
        for( auto command : commands ){
            if( command > 0 ){
                for( int i = 1; i <=command; i++){
                    x += dx[dir];
                    y += dy[dir];
                    if( m[x].count(y) ){
                        x -= dx[dir];
                        y -= dy[dir];
                        break;
                    }
                    ans = max(ans, x*x+y*y);
                }
            }else if( command == -1 ){
                dir++;
            }else if( command == -2)
                dir--;
            if( dir < 0 )
                dir = 3;
            else if( dir > 3 )
                dir = 0;
        }
        return ans;
    }
};