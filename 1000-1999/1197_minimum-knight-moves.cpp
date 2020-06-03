//Link: https://leetcode.com/problems/minimum-knight-moves/ 
class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x) + 3, y = abs(y) + 3;
        queue<pair<int, int> > q;
        set<pair<int, int> > v;
        q.push({3, 3});
        v.insert({3, 3});
        int sum = 0 - (x + y);
        int step = 0;
        int xx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
        int yy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto p = q.front();
                int dx = p.first;
                int dy = p.second;
                q.pop();
                if(dx == x && dy == y)
                    return step;
                for(int i = 0; i < 8; ++i) {
                    int nx = xx[i] + dx;
                    int ny = yy[i] + dy;
                    if(v.count({nx, ny}) || nx < 0 || ny < 0 || nx > x || ny > y)
                        continue;
                    v.insert({nx, ny});
                    q.push({nx, ny});
                    if(nx == x && ny == y)
                        return step + 1;
                }
            }
            ++step;
        }
        return step;
    }
};