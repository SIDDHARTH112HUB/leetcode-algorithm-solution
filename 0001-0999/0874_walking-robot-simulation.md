[874.walking-robot-simulation](https://leetcode.com/problems/walking-robot-simulation/)  

A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

*   `-2`: turn left 90 degrees
*   `-1`: turn right 90 degrees
*   `1 <= x <= 9`: move forward `x` units

Some of the grid squares are obstacles. 

The `i`\-th obstacle is at grid point `(obstacles[i][0], obstacles[i][1])`

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the **square** of the maximum Euclidean distance that the robot will be from the origin.

**Example 1:**

**Input:** commands = \[4,-1,3\], obstacles = \[\]
**Output:** 25
Explanation: robot will go to (3, 4)

**Example 2:**

**Input:** commands = \[4,-1,4,-2,4\], obstacles = \[\[2,4\]\]
**Output:** 65
**Explanation**: robot will be stuck at (1, 4) before turning left and going to (1, 8)

**Note:**

1.  `0 <= commands.length <= 10000`
2.  `0 <= obstacles.length <= 10000`
3.  `-30000 <= obstacle[i][0] <= 30000`
4.  `-30000 <= obstacle[i][1] <= 30000`
5.  The answer is guaranteed to be less than `2 ^ 31`.  



**Solution:**  

```cpp
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
```
      