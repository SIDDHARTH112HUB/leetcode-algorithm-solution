[554.brick-wall](https://leetcode.com/problems/brick-wall/)  

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the **top** to the **bottom** and cross the **least** bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

**You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.**

**Example:**

  
**Input:** \[\[1,2,2,1\],
  
        \[3,1,2\],
  
        \[1,3,2\],
  
        \[2,4\],
  
        \[3,1,2\],
  
        \[1,3,1,1\]\]
  

  
**Output:** 2
  

  
**Explanation:** 
  
![](https://assets.leetcode.com/uploads/2018/10/12/brick_wall.png)
  

**Note:**

1.  The width sum of bricks in different rows are the same and won't exceed INT\_MAX.
2.  The number of bricks in each row is in range \[1,10,000\]. The height of wall is in range \[1,10,000\]. Total number of bricks of the wall won't exceed 20,000.  



**Solution:**  

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int N = wall.size();
        if( N == 0 ) return 0;
        map<int, int> lenMap;
        int wall_width = accumulate(wall[0].begin(), wall[0].end(), 0);
        int ans = 0;
        for( auto &bricks:wall ){
            int sum = 0;
            for( auto len:bricks){
                if( len == 0 )
                    continue;
                sum+=len;
                if( sum >= wall_width)
                    break;
                lenMap[sum]+=1;
                
            }
        }
        for( auto &iter:lenMap){
            if( iter.second > ans ){
                ans = iter.second;
            }
        }
        return N - ans;
    }
};
```
      