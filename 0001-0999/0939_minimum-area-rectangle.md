[939.minimum-area-rectangle](https://leetcode.com/problems/minimum-area-rectangle/)  

Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

**Example 1:**

  
**Input:** \[\[1,1\],\[1,3\],\[3,1\],\[3,3\],\[2,2\]\]
  
**Output:** 4
  

**Example 2:**

  
**Input:** \[\[1,1\],\[1,3\],\[3,1\],\[3,3\],\[4,1\],\[4,3\]\]
  
**Output:** 2
  

**Note**:

1.  `1 <= points.length <= 500`
2.  `0 <= points[i][0] <= 40000`
3.  `0 <= points[i][1] <= 40000`
4.  All points are distinct.  



**Solution:**  

```cpp
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, map<int, int> > m;
        sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2){
           if( p1[0] == p1[0])
               return p1[1] > p2[1];
            return p1[0] > p2[0];
        });
        for( auto &p:points){
            m[p[0]][p[1]] = 1;
        }
        int ans = INT_MAX;
        for( int i = 0; i<points.size()-1; i++){
            for( int j = i+1; j<points.size(); j++){
                int x1 =points[i][0];
                int y1 =points[i][1];
                int x4 =points[j][0];
                int y4 =points[j][1];
                if( x1 == x4 || y1 == y4 ) continue;
                if( m[x1].count(y4) && m[x4].count(y1) ){
                    ans = min(ans, abs(y4-y1)*abs(x4-x1));
                }
            }
        }
        return ans == INT_MAX?0:ans;
    }
};
```
      