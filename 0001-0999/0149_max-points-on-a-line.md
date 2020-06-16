[149.max-points-on-a-line](https://leetcode.com/problems/max-points-on-a-line/)  

Given _n_ points on a 2D plane, find the maximum number of points that lie on the same straight line.

**Example 1:**

  
**Input:** \[\[1,1\],\[2,2\],\[3,3\]\]
  
**Output:** 3
  
**Explanation:**
  
^
  
|
  
|        o
  
|     o
  
|  o  
  
+------------->
  
0  1  2  3  4
  

**Example 2:**

  
**Input:** \[\[1,1\],\[3,2\],\[5,3\],\[4,1\],\[2,3\],\[1,4\]\]
  
**Output:** 4
  
**Explanation:**
  
^
  
|
  
|  o
  
|     o        o
  
|        o
  
|  o        o
  
+------------------->
  
0  1  2  3  4  5  6
  

**NOTE:** input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.  



**Solution:**  

```cpp
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        //
        int N = points.size();
        if( N == 0 )return 0;
        double dmax = numeric_limits<double>::max();
        
        int max_point = 0;
        
        for( int i = 0; i<N; i++){
            map<double, int> slope;
            double max_slope = 0.0;
            auto &p1 = points[i];
            int same_point = 0;
            for( int j = 0; j<N;j++){
                //if( i == j ) continue;
                auto &p2 = points[j];
                double sl = 0.0;
                if( p1.x == p2.x && p1.y == p2.y ){
                    same_point++;
                    if( slope[max_slope] +same_point > max_point ){
                        max_point = slope[max_slope] +same_point;
                    }
                    continue;
                }else if( p1.x == p2.x  ){
                    sl = dmax;
                }else{
                    sl = ((1.0*(p1.y-p2.y))/(p1.x-p2.x));
                }
                
                int tmp = slope[sl];
                tmp += 1;
                if( tmp+same_point > max_point ){
                    max_point = tmp+same_point;
                    max_slope = sl;
                }
                slope[sl] = tmp;
            }
        }
        return max_point;
    }
};
```
      