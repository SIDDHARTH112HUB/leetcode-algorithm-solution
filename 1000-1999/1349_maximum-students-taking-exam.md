[1349.maximum-students-taking-exam](https://leetcode.com/problems/maximum-students-taking-exam/)  

Given a `m * n` matrix `seats`  that represent seats distributions in a classroom. If a seat is broken, it is denoted by `'#'` character otherwise it is denoted by a `'.'` character.

Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the **maximum** number of students that can take the exam together without any cheating being possible..

Students must be placed in seats in good condition.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/01/29/image.png)

  
**Input:** seats = \[\["#",".","#","#",".","#"\],  
                \[".","#","#","#","#","."\],  
                \["#",".","#","#",".","#"\]\]  
**Output:** 4  
**Explanation:** Teacher can place 4 students in available seats so they don't cheat on the exam.   

**Example 2:**

  
**Input:** seats = \[\[".","#"\],  
                \["#","#"\],  
                \["#","."\],  
                \["#","#"\],  
                \[".","#"\]\]  
**Output:** 3  
**Explanation:** Place all students in available seats.   
  

**Example 3:**

  
**Input:** seats = \[\["#",".","**.**",".","#"\],  
                \["**.**","#","**.**","#","**.**"\],  
                \["**.**",".","#",".","**.**"\],  
                \["**.**","#","**.**","#","**.**"\],  
                \["#",".","**.**",".","#"\]\]  
**Output:** 10  
**Explanation:** Place students in available seats in column 1, 3 and 5.  

**Constraints:**

*   `seats` contains only characters `'.' and``'#'.`
*   `m == seats.length`
*   `n == seats[i].length`
*   `1 <= m <= 8`
*   `1 <= n <= 8`  



**Solution:**  

```cpp
class Solution {
public:
    map< unsigned long long, int> dp;
    int m;
    int n;
    
    int maxStudents(vector<vector<char>>& seats) {
        m = seats.size();
        n = seats[0].size();
        return max(h(seats, 0, 1), h(seats, n-1, -1));
    }
    
    int h(vector<vector<char>>& seats, int y, int b) {
        if( y < 0) return 0;
        if(y >= n) return 0;
        static int d[6][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0,  1}, {1, -1}, {1, 1}};
        int res = 0;
        for(int i  = 0; i <m; ++i) {
            if(seats[i][y] == '#') continue;
            bool f = true;
            for(int j = 0; j < 6; ++j) {
                int nx = i + d[j][0];
                int ny = y + d[j][1];
                if(nx <0 || ny <0 || nx >= m ||ny >= n) continue;
                if(seats[nx][ny] == 'S') {
                    f = false;
                    break;
                }
            }
            if(f == false) continue;
            ++res;
            seats[i][y] = 'S';
        }
        
        res += h(seats, y +b, b);
        for(int i  = 0; i <m; ++i) {
            if(seats[i][y] == 'S')
                seats[i][y] = '.';
        }
        return max(res, h(seats, y + b, b));
    }
};
```
      