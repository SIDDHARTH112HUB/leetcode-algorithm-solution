[963.minimum-area-rectangle-ii](https://leetcode.com/problems/minimum-area-rectangle-ii/)  

Given a set of points in the xy-plane, determine the minimum area of **any** rectangle formed from these points, with sides **not necessarily parallel** to the x and y axes.

If there isn't any rectangle, return 0.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/21/1a.png)

  
**Input:** \[\[1,2\],\[2,1\],\[1,0\],\[0,1\]\]
  
**Output:** 2.00000
  
**Explanation:** The minimum area rectangle occurs at \[1,2\],\[2,1\],\[1,0\],\[0,1\], with an area of 2.
  

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/22/2.png)

  
**Input:** \[\[0,1\],\[2,1\],\[1,1\],\[1,0\],\[2,0\]\]
  
**Output:** 1.00000 **Explanation:** The minimum area rectangle occurs at \[1,0\],\[1,1\],\[2,1\],\[2,0\], with an area of 1.
  

**Example 3:**

![](https://assets.leetcode.com/uploads/2018/12/22/3.png)

  
**Input:** \[\[0,3\],\[1,2\],\[3,1\],\[1,3\],\[2,1\]\]
  
**Output:** 0 **Explanation:** There is no possible rectangle to form from these points.
  

**Example 4:**

![](https://assets.leetcode.com/uploads/2018/12/21/4c.png)

  
**Input:** \[\[3,1\],\[1,1\],\[0,1\],\[2,1\],\[3,3\],\[3,2\],\[0,2\],\[2,3\]\]
  
**Output:** 2.00000 **Explanation:** The minimum area rectangle occurs at \[2,1\],\[2,3\],\[3,3\],\[3,1\], with an area of 2.
  

**Note:**

1.  `1 <= points.length <= 50`
2.  `0 <= points[i][0] <= 40000`
3.  `0 <= points[i][1] <= 40000`
4.  All points are distinct.
5.  Answers within `10^-5` of the actual value will be accepted as correct.  



**Solution:**  

```cpp
class Solution {
public:
    double dist(int x1, int y1, int x2, int y2){
        return sqrt((x1 - x2 )* (x1-x2) + (y1-y2) * (y1-y2) );
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<long long, vector<vector<int> > > m;
        int size = points.size();
        for( int i = 0; i < size; i++ ){
            for( int j = i+1; j< size; j++){
                auto &p1 = points[i];
                auto &p2 = points[j];
                long long key = ((long long)(p1[0] + p2[0]) << 16) + (p1[1] + p2[1]);
                m[key].push_back({p1[0], p1[1], p2[0], p2[1]});
            }
        }
        double ans = 0;
        for( auto &it : m){
            for( int i = 0; i < it.second.size(); i++ ){
                for( int j = i+1; j < it.second.size(); j++){
                    auto &p1 = it.second[i];
                    auto &p2 = it.second[j];
                    if( (p1[0] -p2[0] ) * (p1[0] - p2[2]) + (p1[1] - p2[1] )*( p1[1] -p2[3]) == 0  ){
                        double area = dist(p1[0],p1[1], p2[0],p2[1]) * dist(p1[0],p1[1], p2[2], p2[3]);
                        if( ans == 0 || ans > area ) 
                            ans = area;
                    }
                }
            }
        }
        return ans;
    }
};
```
      