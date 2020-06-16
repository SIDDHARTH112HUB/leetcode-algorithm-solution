[490.the-maze](https://leetcode.com/problems/the-maze/)  

There is a **ball** in a maze with empty spaces and walls. The ball can go through empty spaces by rolling **up**, **down**, **left** or **right**, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's **start position**, the **destination** and the **maze**, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

**Example 1:**

  
**Input 1:** a maze represented by a 2D array
  

  
0 0 1 0 0
  
0 0 0 0 0
  
0 0 0 1 0
  
1 1 0 1 1
  
0 0 0 0 0
  

  
**Input 2:** start coordinate (rowStart, colStart) = (0, 4)
  
**Input 3:** destination coordinate (rowDest, colDest) = (4, 4)
  

  
**Output:** true
  

  
**Explanation:** One possible way is : left -> down -> left -> down -> right -> down -> right.
  
![](https://assets.leetcode.com/uploads/2018/10/12/maze_1_example_1.png)
  

**Example 2:**

  
**Input 1:** a maze represented by a 2D array
  

  
0 0 1 0 0
  
0 0 0 0 0
  
0 0 0 1 0
  
1 1 0 1 1
  
0 0 0 0 0
  

  
**Input 2:** start coordinate (rowStart, colStart) = (0, 4)
  
**Input 3:** destination coordinate (rowDest, colDest) = (3, 2)
  

  
**Output:** false
  

  
**Explanation:** There is no way for the ball to stop at the destination.
  
![](https://assets.leetcode.com/uploads/2018/10/13/maze_1_example_2.png)
  

**Note:**

1.  There is only one ball and one destination in the maze.
2.  Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
3.  The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
4.  The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.  



**Solution:**  

```cpp
class Solution {
public:
    int hash(int x, int y) {
        return  (x << 8) | y;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<int> q;
        map<int, int> v;
        int m = maze.size(), n = maze[0].size();
        int h = hash(start[0], start[1]);
        q.push(h);
        v[h] = 0;
        int ans = INT_MAX;
        int d[5] = {0, -1, 0, 1, 0};
        while(q.size()) {
            int p = q.front(); q.pop();
            int x =  p >> 8, y = p & 0xff;
            if(p == hash(destination[0], destination[1])) {
                return true;
            }
            for(int i = 0; i < 4; ++i) {
                int nx = x, ny = y;
                int step = v[p];
                while(nx >= 0 && ny >=0 && nx < m && ny < n && maze[nx][ny] == 0) {
                    nx += d[i]; ny += d[i+1];
                    ++step;
                }
                nx -= d[i]; ny -= d[i+1];
                --step;
                int nh = hash(nx, ny);
                if(v.count(nh) == 0 || step < v[nh]) {
                    v[nh] = step;
                    q.push(nh);
                }
            }
        }
        return false;
    }
};
```
      