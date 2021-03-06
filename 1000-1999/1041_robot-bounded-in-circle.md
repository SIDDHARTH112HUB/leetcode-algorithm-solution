[1041.robot-bounded-in-circle](https://leetcode.com/problems/robot-bounded-in-circle/)  

On an infinite plane, a robot initially stands at `(0, 0)` and faces north.  The robot can receive one of three instructions:

*   `"G"`: go straight 1 unit;
*   `"L"`: turn 90 degrees to the left;
*   `"R"`: turn 90 degress to the right.

The robot performs the `instructions` given in order, and repeats them forever.

Return `true` if and only if there exists a circle in the plane such that the robot never leaves the circle.

**Example 1:**

  
**Input:** "GGLLGG"  
**Output:** true  
**Explanation: **  
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).  
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.  

**Example 2:**

  
**Input:** "GG"  
**Output:** false  
**Explanation: **  
The robot moves north indefinitely.  

**Example 3:**

  
**Input:** "GL"  
**Output:** true  
**Explanation: **  
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...  

**Note:**

1.  `1 <= instructions.length <= 100`
2.  `instructions[i]` is in `{'G', 'L', 'R'}`  



**Solution:**  

```cpp
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
```
      