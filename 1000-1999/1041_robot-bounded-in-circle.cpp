//Link: https://leetcode.com/problems/robot-bounded-in-circle/ 
class Solution {
public:
    bool isRobotBounded(string instructions) {
        set<pair<int, int> > m;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int dir = 0;
        int x = 0, y = 0;
        bool isG = false;
        int cnt = 0;
        int mx = 0;
        int cur = 0;
        while(cnt++ < 2) {
            int c2 = 0;
            while(c2++ < 100){
                for(int i = 0; i < instructions.size(); ++i) {
                    char c = instructions[i];
                    if ( c == 'G') {
                        isG =true;
                        x += dx[dir];
                        y += dy[dir];
                        if (cnt > 1) {
                        if(m.count({x, y}) == 0)
                            return false;
                        }
                        m.insert({x, y});
                    }else if( c == 'L') {
                        dir += 1;
                    }else 
                        dir -= 1;

                    if(dir < 0)
                        dir = 3;
                    if( dir > 3)
                        dir = 0;
                }
                
            }
        }
        return true;
    }
};